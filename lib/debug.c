#include <debug.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// Don't raise a warning about unsafe usage of __builtin_frame_address.
// We know that we will have a calling function, so calling with id = 1 is safe.

/* Prints the call stack, that is, a list of addresses, one in
	each of the functions we are nested within.  gdb or addr2line
	may be applied to kernel.o to translate these into file names,
	line numbers, and function names.  */
void debug_backtrace(void)
{
	static bool explained;
	void** frame;

	printf("Call stack: %p", __builtin_return_address(0));
#pragma GCC diagnostic ignored "-Wframe-address"
	for (frame = __builtin_frame_address(1);
		  (uintptr_t) frame >= 0x1000 && frame[0] != NULL;
		  frame = frame[0])
#pragma GCC diagnostic pop
		printf(" %p", frame[1]);
	printf(".\n");

	if (!explained) {
		explained = true;
		printf(
			 "The `backtrace' program can make call stacks useful.\n"
			 "Read \"Backtraces\" in the \"Debugging Tools\" chapter\n"
			 "of the Pintos documentation for more information.\n");
	}
}
