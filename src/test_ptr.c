#include <ctest.h>
#include <ft_printf.h>
#include <stdio.h>
#include <test.h>
#include <time.h>
///////////////////////////////////////
//              P   Flag             //
///////////////////////////////////////

CTEST_DATA(ptr_test)
{
	t_buff buff;
	char *format;
	char *s;
	clock_t t;
	double time_taken;
};

CTEST_SETUP(ptr_test)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->s =  "hello";
	data->t = clock();
}

CTEST_TEARDOWN(ptr_test)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(ptr_test, with_only_flag)
{
	data->format = "%p";
	data->buff.expected_ret = printf(data->format, data->s);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(ptr_test, two_flags)
{

	data->format = "%p%p";
	data->buff.expected_ret = printf("%p0x0", data->s); // hard coded 0x0 because on linux output is different
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s, NULL);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(ptr_test, with_p_flag_in_the_end)
{
	data->format = "Simple str with an ptr: %p";
	data->buff.expected_ret = printf(data->format, data->s);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(ptr_test, with_p_flag_in_the_middle)
{
	data->format = "Simple str with an ptr: %p in the middle";
	data->buff.expected_ret = printf(data->format, data->s);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(ptr_test, null_prt)
{
	data->format = "|%6p|";
	data->s = NULL;
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	// hardcoded output because on linux output is diffente
	ASSERT_STR("|   0x0|", data->buff.actual);
}

CTEST2(ptr_test, with_right_padding)
{
	data->format = "|%-20p|";
	data->buff.expected_ret = printf(data->format, data->s);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(ptr_test, precision_bigger)
{
	data->format = "|%.50p|";
	data->buff.expected_ret = printf(data->format, data->s);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(ptr_test, precision_bigger_and_null)
{
	data->format = "|%.50p|";
	data->buff.actual_ret = ft_printf(data->format, NULL);
	get_output_from_actual(&(data->buff));
	// hardcoded output because on linux output is diffente
	ASSERT_STR("|0x00000000000000000000000000000000000000000000000000|", data->buff.actual);

}


CTEST2(ptr_test, precision_smaller)
{
	data->format = "|%.5p|";
	data->buff.expected_ret = printf(data->format, data->s);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(ptr_test, precision_smaller_and_null)
{
	data->format = "|%.5p|";
	data->buff.expected_ret = printf(data->format, NULL);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, NULL);
	get_output_from_actual(&(data->buff));
	// hardcoded output because on linux output is diffente
	ASSERT_STR("|0x00000|", data->buff.actual);
}

CTEST2(ptr_test, precision_and_width)
{
	data->format = "|%50.5p|";
	data->buff.expected_ret = printf(data->format, data->s);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}
