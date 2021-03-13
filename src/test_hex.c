#include <ctest.h>
#include <test.h>
#include <ft_printf.h>
#include <time.h>
///////////////////////////////////////
//              x  Flags             //
///////////////////////////////////////

CTEST_DATA(x_test_lower)
{
	t_buff buff;
	int i;
	char *format;
	clock_t t;
	double time_taken;
};

CTEST_SETUP(x_test_lower)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->i = 123456;
	data->t = clock();
}

CTEST_TEARDOWN(x_test_lower)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(x_test_lower, no_modifier_only_flag)
{
	data->format = "%x";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, no_modifier_in_the_middle)
{
	data->format = "this is a %x hex";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, no_modifier_in_the_middle_num_0)
{
	data->format = "this is a %x hex";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, no_modifier_in_the_beg)
{
	data->format = "%x is a hex number";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, no_modifier_in_the_end)
{
	data->format = "\nnow in the end %x\n";
	data->buff.expected_ret = printf(data->format, 4294967295u);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, 4294967295u);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_bigger)
{
	data->format = "|%50x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_smaller)
{
	data->format = "|%1x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_bigger_and_0)
{
	data->format = "|%50x|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_and_left_align)
{
	data->format = "|%-50x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, precision_bigger)
{
	data->format = "|%.50x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, precision_smaller)
{
	data->format = "|%.2x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, zero_padding)
{
	data->format = "|%020x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_and_precision)
{
	data->format = "|%20.40x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_and_precision_smaller)
{
	data->format = "|%3.3x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_and_precision_smaller_and_left_align)
{
	data->format = "|%-3.3x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_and_precision_bigger_left_align)
{
	data->format = "|%-40.40x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_and_precision_bigger_left_align_and_zero)
{
	data->format = "|lala la la %-40.40x|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, zero_padding_width_and_precision_smaller)
{
	data->format = "|%03.3x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, zero_padding_width_and_precision_bigger)
{
	data->format = "|%040.40x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, zero_padding_width_and_precision_bigger_and_zero)
{
	data->format = "|lala la la %040.40x|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, diff_order_zero_padding_width_and_precision_smaller_and_left_align)
{
	data->format = "|%0-3.3x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, diff_order_zero_padding_width_and_precision_bigger_left_align)
{
	data->format = "|%0-40.40x|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, diff_order_zero_padding_width_and_precision_bigger_left_align_and_zero)
{
	data->format = "|lala la la %0-40.40x|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, precision_and_zero)
{
	data->format = "|%.0x|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, precision_not_specified_and_zero)
{
	data->format = "|%.x|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_lower, width_precision_not_specified_and_zero)
{
	data->format = "|%5.x|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}


///////////////////////////////////////
//              X  Flags             //
///////////////////////////////////////

CTEST_DATA(x_test_upper)
{
	t_buff buff;
	int i;
	char *format;
	clock_t t;
	double time_taken;
};

CTEST_SETUP(x_test_upper)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->i = 123456;
	data->t = clock();
}

CTEST_TEARDOWN(x_test_upper)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(x_test_upper, no_modifier_only_flag)
{
	data->format = "%X";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, no_modifier_in_the_middle)
{
	data->format = "this is a %X hex";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, no_modifier_in_the_middle_num_0)
{
	data->format = "this is a %X hex";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, no_modifier_in_the_beg)
{
	data->format = "%X is a hex number";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, no_modifier_in_the_end)
{
	data->format = "now in the end %X";
	data->buff.expected_ret = printf(data->format, 4294967295u);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, 4294967295u);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_bigger)
{
	data->format = "|%50X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_smaller)
{
	data->format = "|%1X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_bigger_and_0)
{
	data->format = "|%50X|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_and_left_align)
{
	data->format = "|%-50X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, precision_bigger)
{
	data->format = "|%.50X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, precision_smaller)
{
	data->format = "|%.2X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, zero_padding)
{
	data->format = "|%020X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_and_precision)
{
	data->format = "|%20.40X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_and_precision_smaller)
{
	data->format = "|%3.3X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_and_precision_smaller_and_left_align)
{
	data->format = "|%-3.3X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_and_precision_bigger_left_align)
{
	data->format = "|%-40.40X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_and_precision_bigger_left_align_and_zero)
{
	data->format = "|lala la la %-40.40X|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, zero_padding_width_and_precision_smaller)
{
	data->format = "|%03.3X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, zero_padding_width_and_precision_bigger)
{
	data->format = "|%040.40X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, zero_padding_width_and_precision_bigger_and_zero)
{
	data->format = "|lala la la %040.40X|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, diff_order_zero_padding_width_and_precision_smaller_and_left_align)
{
	data->format = "|%0-3.3X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, diff_order_zero_padding_width_and_precision_bigger_left_align)
{
	data->format = "|%0-40.40X|";
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, diff_order_zero_padding_width_and_precision_bigger_left_align_and_zero)
{
	data->format = "|lala la la %0-40.40X|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, precision_and_zero)
{
	data->format = "|%.0X|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, precision_not_specified_and_zero)
{
	data->format = "|%.X|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(x_test_upper, width_precision_not_specified_and_zero)
{
	data->format = "|%5.X|";
	data->i = 0;
	data->buff.expected_ret = printf(data->format, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf(data->format, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}
