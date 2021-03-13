#include <ctest.h>
#include <ft_printf.h>
#include <test.h>
#include <limits.h>
#include <time.h>
///////////////////////////////////////
//              d Flag             //
///////////////////////////////////////


CTEST_DATA(d_test)
{
	t_buff buff;
	int i;
	char *format;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	long int long_num;
	clock_t t;
	double time_taken;

};

CTEST_SETUP(d_test)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->i = 123456;

	data->a = 5;
	data->b = 12;
	data->c = 123;
	data->d = 1234;
	data->e = 12345;
	data->f = -5;
	data->g = -999999999;
	data->h = 0;
	data->long_num = 0x12FFFFFFFF;
	data->t = clock();
}

CTEST_TEARDOWN(d_test)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(d_test, with_five_digits_number)
{
	data->format = "%d";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_long_int)
{
	data->format = "%d";
	data->buff.expected_ret = printf(data->format, data->long_num);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->long_num);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, int_min)
{
	data->format = "%-d";
	data->buff.expected_ret = printf(data->format, INT_MIN);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, INT_MIN);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_flag_negative_width_negative_number)
{
	data->format = "%0*d";
	data->buff.expected_ret = printf(data->format, -7, -54);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, -7, -54);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_only_flag_three_digits)
{
	data->format = "%d";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_small_negative_number)
{
	data->format = "this is a test with a negative number %d";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_big_negative_number)
{
	data->format = "this is a test with a negative number %d";
	data->buff.expected_ret = printf(data->format, data->g);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->g);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_d_flag_in_the_end)
{
	data->format = "Simple str with an int: %d";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_d_flag_in_the_middle)
{
	data->format = "Simple str with an int: %d in the middle";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_d_flag_in_the_beg_and_middle)
{
	data->format = "%d simple str with an int: %d in the middle";
	data->buff.expected_ret = printf(data->format, data->c, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, with_two_flags_together)
{
	data->format = "---> %d%d <---";
	data->buff.expected_ret = printf(data->format, data->c, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_modifier)
{
	data->format = "|%20d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_negative_arg)
{
	data->format = "|%*d|";
	data->buff.expected_ret = printf(data->format, data->f, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_and_negative_number)
{
	data->format = "|%-*d|";
	data->buff.expected_ret = printf(data->format, 70, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, 70, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_negative_num_and_precision)
{
	data->format = "|%.*d|";
	data->buff.expected_ret = printf(data->format, 5, data->g);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, 5, data->g);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_7_right_align)
{
	data->format = "|%7d|";
	data->a = 33;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_7_right_align_and_neg_number)
{
	data->format = "|%7d|";
	data->a = -14;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_3_right_align)
{
	data->format = "|%3d|";
	data->a = 0;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_5_right_align_neg_number)
{
	data->format = "|%5d|";
	data->a = -2562;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_4_right_align_neg_number)
{
	data->format = "|%4d|";
	data->a = -2464;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_7_left_align_and_neg_number)
{
	data->format = "|%-7d|";
	data->a = -14;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_5_left_align)
{
	data->format = "|%-5d|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_5_left_align_neg_number)
{
	data->format = "|%-5d|";
	data->a = -2562;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_4_left_align)
{
	data->format = "|%-4d|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_4_left_align_neg_number)
{
	data->format = "|%-4d|";
	data->a = -2464;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_smaller_than_len)
{
	data->format = "|%.2d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_smaller_than_len_with_neg_number)
{
	data->format = "|%.1d|";
	data->buff.expected_ret = printf(data->format, data->g);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->g);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_bigger_than_len)
{
	data->format = "|%.20d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_bigger_than_len_with_neg_number)
{
	data->format = "|%.20d|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_7_right_align_and_neg_number)
{
	data->format = "|%.7d|";
	data->a = -14;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_5_right_align)
{
	data->format = "|%.5d|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_5_right_align_neg_number)
{
	data->format = "|%.5d|";
	data->a = -2562;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_4_right_align)
{
	data->format = "|%.4d|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_4_right_align_neg_number)
{
	data->format = "|%.4d|";
	data->a = -2464;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_0_right_align)
{
	data->format = "|%.0d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_0_and_zero)
{
	data->format = "|%.0d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_without_size_and_zero)
{
	data->format = "|%.d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_0_width_5_and_zero)
{
	data->format = "|%5.0d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_not_specified_width_5_and_zero)
{
	data->format = "|%5.d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_0_width_5_and_zero_left_aligned)
{
	data->format = "|%-5.0d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, precision_not_specified_5_and_zero_left_aligned)
{
	data->format = "|%-5.d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_4_right_align_0_padding)
{
	data->format = "|%04d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_7_right_align_0_padding_neg_number)
{
	data->format = "|%07d|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_3_right_align_0_padding)
{
	data->format = "|%03d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_3_right_align_0_padding_same_width_neg_num)
{
	data->format = "|%03d|";
	data->c = -123;
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_5_right_align_0_padding_neg_num)
{
	data->format = "|%05d|";
	data->c = -123;
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_2_right_align_0_padding_smaller_width_neg_num)
{
	data->format = "|%02d|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_5_left_align_0_padding)
{
	data->format = "|%0-5d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_4_left_align_0_padding)
{
	data->format = "|%-04d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_and_precision)
{
	data->format = "|%8.5d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_and_precision_bigger)
{
	data->format = "|%30.35d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_2_digits_and_precision)
{
	data->format = "|%10.5d|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_2_digits_and_precision_neg_number)
{
	data->format = "|%10.5d|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_and_precision_and_zero)
{
	data->format = "|%9.5d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_and_precision_smaller)
{
	data->format = "|%9.2d|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_and_precision_same)
{
	data->format = "|%5.5d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, width_and_precision_same_and_smaller)
{
	data->format = "|%3.3d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, left_align_width_and_precision)
{
	data->format = "|%-8.5d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, left_align_width_2_digits_and_precision)
{
	data->format = "|%-10.5d|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, left_align_width_2_digits_and_precision_neg_number)
{
	data->format = "|%-10.5d|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, left_align_width_and_precision_and_zero)
{
	data->format = "|%-9.5d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, left_align_width_and_precision_smaller)
{
	data->format = "|%-9.2d|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, left_align_width_and_precision_same)
{
	data->format = "|%-5.5d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, left_align_width_and_precision_same_and_smaller)
{
	data->format = "|%-3.3d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_and_precision_5)
{
	data->format = "|%08.5d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_2_digits_and_precision)
{
	data->format = "|%010.5d|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_2_digits_and_precision_neg_number)
{
	data->format = "|%010.5d|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_and_precision_and_zero)
{
	data->format = "|%09.5d|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_and_precision_smaller)
{
	data->format = "|%09.2d|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_and_precision_same)
{
	data->format = "|%05.5d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_and_precision_same_and_smaller)
{
	data->format = "|%03.3d|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(d_test, zero_padding_width_and_precision)
{
	data->format = "|%0-8.5d|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

///////////////////////////////////////
//              i Flag             //
///////////////////////////////////////

CTEST_DATA(i_test)
{
	t_buff buff;
	int i;
	char *format;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	long int long_num;
	clock_t t;
	double time_taken;

};

CTEST_SETUP(i_test)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->i = 123456;

	data->a = 5;
	data->b = 12;
	data->c = 123;
	data->d = 1234;
	data->e = 12345;
	data->f = -5;
	data->g = -999999999;
	data->h = 0;
	data->long_num = 0x12FFFFFFFF;
	data->t = clock();
}

CTEST_TEARDOWN(i_test)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(i_test, from_other_test)
{
	data->buff.expected_ret = printf("%-3.7i", -2375);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%0-3.7i", -2375);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_five_digits_number)
{
	data->format = "%i";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}


CTEST2(i_test, basic_with_neg_number)
{
	data->format = "this %i number";
	data->buff.expected_ret = printf(data->format, -267);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, -267);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_long_int)
{
	data->format = "%i";
	data->buff.expected_ret = printf(data->format, data->long_num);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->long_num);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_only_flag)
{
	data->format = "%i";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_small_negative_number)
{
	data->format = "this is a test with a negative number %i";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_big_negative_number)
{
	data->format = "this is a test with a negative number %i";
	data->buff.expected_ret = printf(data->format, data->g);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->g);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_d_flag_in_the_end)
{
	data->format = "Simple str with an int: %i";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_d_flag_in_the_middle)
{
	data->format = "Simple str with an int: %i in the middle";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_d_flag_in_the_beg_and_middle)
{
	data->format = "%i simple str with an int: %i in the middle";
	data->buff.expected_ret = printf(data->format, data->c, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, with_two_flags_together)
{
	data->format = "---> %i%i <---";
	data->buff.expected_ret = printf(data->format, data->c, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_modifier)
{
	data->format = "|%20d|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_negative_arg)
{
	data->format = "|%*i|";
	data->buff.expected_ret = printf(data->format, data->f, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_and_negative_number)
{
	data->format = "|%-*i|";
	data->buff.expected_ret = printf(data->format, 7, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, 7, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_negative_num_and_precision)
{
	data->format = "|%.*i|";
	data->buff.expected_ret = printf(data->format, 5, data->g);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, 5, data->g);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_7_right_align_and_neg_number)
{
	data->format = "|%7i|";
	data->a = -14;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_3_right_align)
{
	data->format = "|%3i|";
	data->a = 0;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_5_right_align)
{
	data->format = "|%5i|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_5_right_align_neg_number)
{
	data->format = "|%5i|";
	data->a = -2562;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_4_right_align)
{
	data->format = "|%4i|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_4_right_align_neg_number)
{
	data->format = "|%4i|";
	data->a = -2464;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}


CTEST2(i_test, width_7_right_align)
{
	data->format = "|%7i|";
	data->a = 33;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_7_left_align_and_neg_number)
{
	data->format = "|%-7i|";
	data->a = -14;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_3_left_align)
{
	data->format = "|%-3i|";
	data->a = 0;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_5_left_align)
{
	data->format = "|%-5i|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_5_left_align_neg_number)
{
	data->format = "|%-5i|";
	data->a = -2562;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_4_left_align)
{
	data->format = "|%-4i|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_4_left_align_neg_number)
{
	data->format = "|%-4i|";
	data->a = -2464;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_smaller_than_len)
{
	data->format = "|%.2i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_smaller_than_len_with_neg_number)
{
	data->format = "|%.1i|";
	data->buff.expected_ret = printf(data->format, data->g);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->g);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_and_precision_bigger)
{
	data->format = "|%30.35i|";
	data->buff.expected_ret = printf(data->format, -10);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, -10);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(i_test, precision_bigger_than_len)
{
	data->format = "|%.20i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_bigger_than_len_with_neg_number)
{
	data->format = "|%.20i|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_bigger_than_len_and_width)
{
	data->format = "|%.30i|";
	data->buff.expected_ret = printf(data->format, data->d);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->d);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_7_right_align)
{
	data->format = "|%.7i|";
	data->a = 33;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_7_right_align_and_neg_number)
{
	data->format = "|%.7i|";
	data->a = -14;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_3_right_align)
{
	data->format = "|%.3i|";
	data->a = 0;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_5_right_align)
{
	data->format = "|%.5i|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_5_right_align_neg_number)
{
	data->format = "|%.5i|";
	data->a = -2562;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_4_right_align)
{
	data->format = "|%.4i|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_4_right_align_neg_number)
{
	data->format = "|%.4i|";
	data->a = -2464;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_0_right_align)
{
	data->format = "|%.0i|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_0_and_zero)
{
	data->format = "|%.0i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_without_size_and_zero)
{
	data->format = "|%.i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_0_width_5_and_zero)
{
	data->format = "|%5.0i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_not_specified_width_5_and_zero)
{
	data->format = "|%5.i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_0_width_5_and_zero_left_aligned)
{
	data->format = "|%-5.0i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, precision_not_specified_5_and_zero_left_aligned)
{
	data->format = "|%-5.i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_4_right_align_0_padding)
{
	data->format = "|%04i|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_7_right_align_0_padding_neg_number)
{
	data->format = "|%07i|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_3_right_align_0_padding)
{
	data->format = "|%03i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_3_right_align_0_padding_same_width_neg_num)
{
	data->format = "|%03i|";
	data->c = -123;
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_5_right_align_0_padding_neg_num)
{
	data->format = "|%05i|";
	data->c = -123;
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_2_right_align_0_padding_smaller_width_neg_num)
{
	data->format = "|%02i|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_5_left_align_0_padding)
{
	data->format = "|%0-5i|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_4_left_align_0_padding)
{
	data->format = "|%-04i|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_and_precision)
{
	data->format = "|%8.5i|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_2_digits_and_precision)
{
	data->format = "|%10.5i|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_2_digits_and_precision_neg_number)
{
	data->format = "|%10.5i|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_and_precision_and_zero)
{
	data->format = "|%9.5i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_and_precision_smaller)
{
	data->format = "|%9.2i|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_and_precision_same)
{
	data->format = "|%5.5i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, width_and_precision_same_and_smaller)
{
	data->format = "|%3.3i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, left_align_width_and_precision)
{
	data->format = "|%-8.5i|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, left_align_width_2_digits_and_precision)
{
	data->format = "|%-10.5i|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, left_align_width_2_digits_and_precision_neg_number)
{
	data->format = "|%-10.5i|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, left_align_width_and_precision_and_zero)
{
	data->format = "|%-9.5i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, left_align_width_and_precision_smaller)
{
	data->format = "|%-9.2i|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, left_align_width_and_precision_same)
{
	data->format = "|%-5.5i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, left_align_width_and_precision_same_and_smaller)
{
	data->format = "|%-3.3i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_and_precision_5_i)
{
	data->format = "|%08.5i|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_2_digits_and_precision)
{
	data->format = "|%010.5i|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_2_digits_and_precision_neg_number)
{
	data->format = "|%010.5i|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_and_precision_and_zero)
{
	data->format = "|%09.5i|";
	data->buff.expected_ret = printf(data->format, data->h);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->h);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_and_precision_smaller)
{
	data->format = "|%09.2i|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_and_precision_same)
{
	data->format = "|%05.5i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_and_precision_same_and_smaller)
{
	data->format = "|%03.3i|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(i_test, zero_padding_width_and_precision_5_i_left_align)
{
	data->format = "|%0-8.5i|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}


// ///////////////////////////////////////
// //              u Flag             //
// ///////////////////////////////////////

CTEST_DATA(u_test)
{
	t_buff buff;
	int i;
	char *format;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	long int long_num;
	clock_t t;
	double time_taken;

};

CTEST_SETUP(u_test)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->i = 123456;

	data->a = 5;
	data->b = 12;
	data->c = 123;
	data->d = 1234;
	data->e = 12345;
	data->f = 0;
	data->long_num = 0x12FFFFFFFF;
	data->t = clock();
}

CTEST_TEARDOWN(u_test)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(u_test, with_five_digits_number)
{
	data->format = "%u";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, with_long_int)
{
	data->format = "%u";
	data->buff.expected_ret = printf(data->format, data->long_num);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->long_num);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, with_only_flag)
{
	data->format = "%u";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, with_d_flag_in_the_end)
{
	data->format = "Simple str with an int: %u";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, with_d_flag_in_the_middle)
{
	data->format = "Simple str with an int: %u in the middle";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, with_d_flag_in_the_beg_and_middle)
{
	data->format = "%u simple str with an int: %u in the middle";
	data->buff.expected_ret = printf(data->format, data->c, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, with_two_flags_together)
{
	data->format = "---> %u%u <---";
	data->buff.expected_ret = printf(data->format, data->c, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_modifier)
{
	data->format = "|%20u|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_7_right_align)
{
	data->format = "|%7u|";
	data->a = 33;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_3_right_align)
{
	data->format = "|%3u|";
	data->a = 0;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_5_right_align)
{
	data->format = "|%5u|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_4_right_align)
{
	data->format = "|%4u|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_3_left_align)
{
	data->format = "|%-3u|";
	data->a = 0;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_5_left_align)
{
	data->format = "|%-5u|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_4_left_align)
{
	data->format = "|%-4u|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_smaller_than_len)
{
	data->format = "|%.2u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_bigger_than_len)
{
	data->format = "|%.20u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_bigger_than_len_and_width)
{
	data->format = "|%.30u|";
	data->buff.expected_ret = printf(data->format, data->d);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->d);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_7_right_align)
{
	data->format = "|%.7u|";
	data->a = 33;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_3_right_align)
{
	data->format = "|%.3u|";
	data->a = 0;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_5_right_align)
{
	data->format = "|%.5u|";
	data->a = 52625;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_4_right_align)
{
	data->format = "|%.4u|";
	data->a = 94827;
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_0_right_align)
{
	data->format = "|%.0u|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_0_and_zero)
{
	data->format = "|%.0u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_without_size_and_zero)
{
	data->format = "|%.u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_0_width_5_and_zero)
{
	data->format = "|%5.0u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_not_specified_width_5_and_zero)
{
	data->format = "|%5.u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_0_width_5_and_zero_left_aligned)
{
	data->format = "|%-5.0u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, precision_not_specified_5_and_zero_left_aligned)
{
	data->format = "|%-5.u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_4_right_align_0_padding)
{
	data->format = "|%04u|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_3_right_align_0_padding)
{
	data->format = "|%03u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_5_left_align_0_padding)
{
	data->format = "|%0-5u|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_4_left_align_0_padding)
{
	data->format = "|%-04u|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_and_precision)
{
	data->format = "|%8.5u|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_2_digits_and_precision)
{
	data->format = "|%10.5u|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_and_precision_and_zero)
{
	data->format = "|%9.5u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_and_precision_smaller)
{
	data->format = "|%9.2u|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_and_precision_same)
{
	data->format = "|%5.5u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, width_and_precision_same_and_smaller)
{
	data->format = "|%3.3u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, left_align_width_and_precision)
{
	data->format = "|%-8.5u|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, left_align_width_2_digits_and_precision)
{
	data->format = "|%-10.5u|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, left_align_width_and_precision_and_zero)
{
	data->format = "|%-9.5u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, left_align_width_and_precision_smaller)
{
	data->format = "|%-9.2u|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, left_align_width_and_precision_same)
{
	data->format = "|%-5.5u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, left_align_width_and_precision_same_and_smaller)
{
	data->format = "|%-3.3u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, zero_padding_width_and_precision_5_u)
{
	data->format = "|%08.5u|";
	data->buff.expected_ret = printf(data->format, data->a);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->a);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, zero_padding_width_2_digits_and_precision)
{
	data->format = "|%010.5u|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, zero_padding_width_and_precision_and_zero)
{
	data->format = "|%09.5u|";
	data->buff.expected_ret = printf(data->format, data->f);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->f);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, zero_padding_width_and_precision_smaller)
{
	data->format = "|%09.2u|";
	data->buff.expected_ret = printf(data->format, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, zero_padding_width_and_precision_same)
{
	data->format = "|%05.5u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, zero_padding_width_and_precision_same_and_smaller)
{
	data->format = "|%03.3u|";
	data->buff.expected_ret = printf(data->format, data->e);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->e);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(u_test, zero_padding_width_and_precision_5_u_left_align)
{
	data->format = "|%0-8.5u|";
	data->buff.expected_ret = printf(data->format, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}
