#include <ctest.h>
#include <ft_printf.h>
#include <stdio.h>
#include <test.h>
#include <time.h>

///////////////////////////////////////
//              %  Flags             //
///////////////////////////////////////


CTEST_DATA(percent_test)
{
	t_buff buff;
	char *format;
	char c;
	clock_t t;
	double time_taken;
};

CTEST_SETUP(percent_test)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->c =  'a';
	data->t = clock();
}

CTEST_TEARDOWN(percent_test)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(percent_test, one_flag)
{
	data->format = "Simple str with wrong arg: %% in the middle";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(percent_test, many_flags)
{
	data->format = "%%%%%%%%%%%%%%%%";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(percent_test, two_precents_followed_by_d)
{
	data->format = "%%d";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(percent_test, followed_by_minus_and_number)
{
	data->format = "%-5%";
	data->buff.expected_ret = printf("%%    ");
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(percent_test, followed_by_minus_precision_and_number)
{
	data->format = "%-.5%";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(percent_test, followed_by_zero_and_number)
{
	data->format = "%05%";
	data->buff.expected_ret = printf("0000%%");
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}
