#include <idc.idc>

static main()
{
	auto flags;
	auto start;
	auto end;
	auto fp;
	auto lu;
	auto elsize;
	auto strType;
	auto strTypeSpace;
	auto arrsize;
	auto cdecl;
	auto nextStart;
	auto name;

//  Message("\nStarting MUT processing.\n");

	start = GetSegmentAttr(ScreenEA(), SEGATTR_START);
	end = GetSegmentAttr(ScreenEA(), SEGATTR_END);
	
	auto fpc = fopen("ram_vars.cpp", "w+");
	auto fph = fopen("ram_vars.h", "w+");

	while (1)
	{
		flags = GetFlags(start);


		if (isWord(flags))
		{
			elsize = 2;
			strType = "u16";
			strTypeSpace = "u16 ";
			
			if (start & 1)
			{
				Message("Align error %08X, name %s\n", start, GetTrueName(start));
			};
		}
		else if (isDwrd(flags))
		{
			elsize = 4;
			strType = "u32";
			strTypeSpace = "u32 ";
			
			if (start & 3)
			{
				Message("Align error %08X, name %s\n", start, GetTrueName(start));
			};
		}
		else
		{
			elsize = 1;
			strType = "byte";
			strTypeSpace = "byte";
		};
		
		if (isUnknown(flags))
		{
			lu = NextHead(start, end) - start;
			nextStart = NextHead(start, end);
		}
		else
		{
			lu = ItemSize(start);
			nextStart = NextNotTail(start);
		};	

		arrsize = lu/elsize;
			
		
		if ((flags & FF_ANYNAME) == 0)
		{
			name = sprintf("unused_%s_%08X", strType, start);
		}
		else
		{
			name = GetTrueName(start);
			
		};
			
		if (arrsize > 1)
		{
			cdecl = sprintf("%s\t%s[%i];", strTypeSpace, name, arrsize);			
		}
		else
		{
			cdecl = sprintf("%s\t%s;", strTypeSpace, name);
		};
			
//		Message("Address %08X, size %04i; %s\n", start, lu, cdecl);

		fprintf(fpc, "%s\n", cdecl);
		fprintf(fph, "extern\t%s\n", cdecl);
			
		start = nextStart;
		
		if (start > end) break;
	};
}

