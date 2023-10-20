int global_var;
int global_var_init = 26;

static int static_var;
static int static_var_init = 25;

static int static_function()
{
	return 0;
}

int global_function(int p)
{
	static int local_static_var;
	static int local_static_var_init=5;

	local_static_var = p;

	return local_static_var_init + local_static_var;
}

int global_function2()
{
	int x;
	int y;
	return x+y;
}

// # nm test.o
// 0000000a T global_function
// 00000025 T global_function2
// 00000004 C global_var
// 00000000 D global_var_init
// 00000004 b local_static_var.1255
// 00000008 d local_static_var_init.1256
// 0000003b T main
// 00000036 T non_mangled_function
// 00000000 t static_function
// 00000000 b static_var
// 00000004 d static_var_init