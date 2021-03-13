#include <ctest.h>
#include <ft_printf.h>
#include <test.h>
#include <time.h>

///////////////////////////////////////
//             Char Flag             //
///////////////////////////////////////

CTEST_DATA(c_test)
{
	t_buff buff;
	char c;
	clock_t t;
	double time_taken;
};

CTEST_SETUP(c_test)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);

	data->c = 'a';
	data->t = clock();
}

CTEST_TEARDOWN(c_test)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(c_test, all_chars)
{
	for (int i = 32; i < 128; ++i)
	{
		data->buff.expected_ret = printf("%c", data->c);
		get_output_from_expected(&(data->buff));
		data->buff.actual_ret = ft_printf("%c", data->c);
		get_output_from_actual(&(data->buff));
		ASSERT_STR(data->buff.expected, data->buff.actual);
		ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
		data->c = i;
	}
}

CTEST2(c_test, two_flags)
{
	data->buff.expected_ret = printf("%c%c", data->c, data->c + 5);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%c%c", data->c, data->c + 5);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, in_the_end)
{
	data->buff.expected_ret = printf("Simple str with an char: %c", data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("Simple str with an char: %c", data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, in_the_middle)
{
	data->buff.expected_ret = printf("Simple str with an char: %c in the middle", data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("Simple str with an char: %c in the middle", data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, width_modifier_in_the_flag)
{
	data->buff.expected_ret = printf("|%20c|", data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%20c|", data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, width_modifier_left_aligned)
{
	data->buff.expected_ret = printf("|%-20c|", data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%-20c|", data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, width_modifier_as_arg)
{
	data->buff.expected_ret = printf("|%*c|", 5, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%*c|", 5, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, width_modifier_as_arg_neg)
{
	data->buff.expected_ret = printf("|%*c|", -5, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%*c|", -5, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, null_char_alone)
{
	data->c = '\0';
	data->buff.expected_ret = printf("|%c|", data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%c|", data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, null_char_plus_width)
{
	data->c = '\0';
	data->buff.expected_ret = printf("|%5c|", data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%5c|", data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, null_char_plus_width_left_align)
{
	data->c = '\0';
	data->buff.expected_ret = printf("|%-5c|", data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%-5c|", data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}

CTEST2(c_test, special_chars_3)
{
	data->buff.expected_ret = printf("|%c| |%c| |%c|", '\n', '\t', '\v');
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("|%c| |%c| |%c|", '\n', '\t', '\v');
	get_output_from_actual(&(data->buff));
	ASSERT_BUFF(data->buff);
}
