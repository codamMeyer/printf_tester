#include <ctest.h>
#include <ft_printf.h>
#include <stdio.h>
#include <test.h>
#include <time.h>
///////////////////////////////////////
//              Str Flag             //
///////////////////////////////////////

CTEST_DATA(s_tests)
{
	t_buff buff;
	char *format;
	char c;
	char *s1;
	char *s2;
	char *s3;
	char *s4;
	char *s_hidden;
	clock_t t;
	double time_taken;
};

CTEST_SETUP(s_tests)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->c =  'a';
	data->s1 = "Hello";
	data->s2 = "World";
	data->s3 = "!";
	data->s4 = "Hello World ! :D";
	data->s_hidden = "hi low\0don't print me lol\0";
	data->t = clock();
}

CTEST_TEARDOWN(s_tests)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(s_tests, with_only_flag)
{
	data->format = "%s";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, with_s_flag_in_the_end)
{
	data->format = "Simple str with a str flag: %s";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, with_s_flag_in_the_middle)
{
	data->format = "Simple str with a str flag: %s in the middle";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, two_flags_together)
{
	data->format = "%s%s";
	data->buff.expected_ret = printf(data->format, data->s1, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, with_empty_str)
{
	data->format = "this should be %shidden";
	data->s1 = "";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_bigger_than_len)
{
	data->format = "%40s";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_bigger_than_len_longer_str)
{
	data->format = "%60s";
	data->buff.expected_ret = printf(data->format, data->s4);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s4);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_smaller_than_len)
{
	data->format = "%6s";
	data->buff.expected_ret = printf(data->format, data->s4);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s4);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_bigger_than_len_left_align)
{
	data->format = "%-40s";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_bigger_than_len_longer_str_left_align)
{
	data->format = "%-60s";
	data->buff.expected_ret = printf(data->format, data->s4);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s4);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_smaller_than_len_left_align)
{
	data->format = "%-6s";
	data->buff.expected_ret = printf(data->format, data->s4);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s4);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_bigger_than_len)
{
	data->format = "%.8s";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_smaller_than_len)
{
	data->format = "go to %.4s";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_not_specified)
{
	data->format = ">%.s<";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_zero)
{
	data->format = ">%.0s<";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, two_flags_with_precision_smaller)
{
	data->format = "%.3s%.2s";
	data->buff.expected_ret = printf(data->format, data->s1, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, two_flags_with_precision_bigger)
{
	data->format = "%.8s%.8s";
	data->buff.expected_ret = printf(data->format, data->s1, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, two_flags_with_precision_and_width)
{
	data->format = "%.4s%8s";
	data->buff.expected_ret = printf(data->format, data->s1, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_and_width)
{
	data->format = ";)%32.4s";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_and_width_left_align)
{
	data->format = "%-32.4s No";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_and_width_zero_padding)
{
	data->format = "%032.4s No";
	data->buff.expected_ret = printf("0000000000000000000000000000Hell No");
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, NULL_str)
{
	data->format = "%s No";
	data->s1 = NULL;
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, NULL_str_with_width)
{
	data->format = "%7s. No";
	data->s1 = NULL;
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2_SKIP(s_tests, NULL_str_with_small_precision)
{
	data->format = "%.2s No";
	data->s1 = NULL;
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, NULL_str_with_0_precision)
{
	data->format = "%.0s No";
	data->s1 = NULL;
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, precision_0)
{
	data->format = "%.0s Hello";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, hidden_str)
{
	data->format = "|%s|";
	data->buff.expected_ret = printf(data->format, data->s_hidden);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s_hidden);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, hidden_str_width_smaller)
{
	data->format = "|%3s|";
	data->buff.expected_ret = printf(data->format, data->s_hidden);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s_hidden);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, hidden_str_width_bigger)
{
	data->format = "|%50s|";
	data->buff.expected_ret = printf(data->format, data->s_hidden);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s_hidden);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, hidden_str_precision_smaller)
{
	data->format = "|%.2s|";
	data->buff.expected_ret = printf(data->format, data->s_hidden);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s_hidden);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, hidden_str_precision_bigger)
{
	data->format = "|%.50s|";
	data->buff.expected_ret = printf(data->format, data->s_hidden);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s_hidden);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, hidden_str_precision_0_before_number)
{
	data->format = "|%.05s|";
	data->buff.expected_ret = printf(data->format, data->s_hidden);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s_hidden);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_5_and_precision_not_specified)
{
	data->format = "|%5.s|";
	data->buff.expected_ret = printf(data->format, data->s4);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s4);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, width_5_and_precision_not_specified_left_align)
{
	data->format = "|%-5.s|";
	data->buff.expected_ret = printf(data->format, data->s4);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s4);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}


CTEST2(s_tests, width_5_only_null_char_left_align)
{
	data->format = "|%-2s|";
	data->s4 = "\0";
	data->buff.expected_ret = printf(data->format, data->s4);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s4);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, exact_precision)
{
	data->format = "|%.5s|";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, wrong_flag)
{
	data->format = "|%-.00s|";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, minus_flag_and_precision)
{
	data->format = "|%-.05s|";
	data->buff.expected_ret = printf(data->format, data->s1);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s1);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, multi_flags_diff_order_same_precision)
{
	data->format = "|%-06.06s|";
	data->buff.expected_ret = printf(data->format, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
	data->format = "|%0-6.06s|";
	data->buff.expected_ret = printf(data->format, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, multi_zeros)
{
	data->format = "|%00s|";
	data->buff.expected_ret = printf(data->format, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
	data->format = "|%-00s|";
	data->buff.expected_ret = printf(data->format, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
	data->format = "|%0-0s|";
	data->buff.expected_ret = printf(data->format, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
	data->format = "|%00-s|";
	data->buff.expected_ret = printf(data->format, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s2);
	get_output_from_actual(&(data->buff));
}

CTEST2(s_tests, minus_and_zero_together)
{
	data->format = "|%-05s|";
	data->buff.expected_ret = printf(data->format, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(s_tests, passing_negative_as_precision)
{
	data->format = "|%.*s|";
	data->s2 = NULL;
	data->buff.expected_ret = printf(data->format, -1, data->s2);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, -3, data->s2);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}
