#include <ctest.h>
#include <test.h>
#include <ft_printf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_LEN 2048
#define READ_PIPE 0
#define WRITE_PIPE 1

CTEST_DATA(general_tests)
{
	char expected[MAX_LEN+1];
	char actual[MAX_LEN+1];
	int pipe[2];
	int saved_stdout_fd;

	clock_t t;
	double time_taken;
};

CTEST_SETUP(general_tests)
{
	if( pipe(data->pipe) != 0 )
    	exit(1);
	data->saved_stdout_fd = dup(STDOUT_FILENO);  /* save stdout for display later */
	dup2(data->pipe[WRITE_PIPE], STDOUT_FILENO);   /* redirect stdout to the pipe */
	close(data->pipe[WRITE_PIPE]);
	data->t = clock();
}

CTEST_TEARDOWN(general_tests)
{
	dup2(data->saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(general_tests, d_flag)
{
	printf("this function shoud print %d in the middle\n", 5);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %d in the middle\n", 5);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, i_flag)
{
	printf("this function shoud print %i in the middle\n", 5);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %i in the middle\n", 5);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, u_flag)
{
	printf("this function shoud print %u in the middle\n", 5);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %u in the middle\n", 5);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, c_flag)
{
	printf("this function shoud print %c in the middle\n", 'A');
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %c in the middle\n", 'A');

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, s_flag)
{
	printf("this function shoud print %s in the middle\n", "LALALALALALA");
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %s in the middle\n", "LALALALALALA");

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, x_flag)
{
	printf("this function shoud print %x in the middle\n", 451315);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %x in the middle\n", 451315);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, X_flag)
{
	printf("this function shoud print %X in the middle\n", 451315);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %X in the middle\n", 451315);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, p_flag)
{
	char *ptr = "hello";
	printf("this function shoud print %p in the middle\n", ptr);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %p in the middle\n", ptr);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, percent_flag)
{
	printf("this function shoud print %% in the middle\n");
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %% in the middle\n");

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, minus)
{
	printf("this function shoud print %-5d in the middle\n", 5);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %-5d in the middle\n", 5);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, asteristic)
{
	printf("this function shoud print %-*d in the middle\n", 20, 5);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %-*d in the middle\n", 20, 5);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST2(general_tests, zero)
{
	printf("this function shoud print %0*d in the middle\n", 20, 5);
	fflush(stdout);

	read(data->pipe[READ_PIPE], data->expected, MAX_LEN); /* read from pipe into buffer */

	ft_printf("this function shoud print %0*d in the middle\n", 20, 5);

	fflush(stdout);

	read(data->pipe[READ_PIPE], data->actual, MAX_LEN); /* read from pipe into buffer */
	ASSERT_STR(data->expected, data->actual);
}

CTEST_DATA(test)
{
	t_buff buff;
	char *format;
	char	c;
	int		d;
	int		e;
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int count;
	int a;
	int b;
	clock_t t;
	double time_taken;
};

CTEST_SETUP(test)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->c = 'a';
	data->d = 2147483647;
	data->e = -2147483648;
	data->i = 8;
	data->j = -12;
	data->k = 123456789;
	data->l = 0;
	data->m = -12345678;
	data->count = 69;
	data->a = -2;
	data->b = -2;
	data->t = clock();
}

CTEST_TEARDOWN(test)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->t = clock() - data->t;
	data->time_taken = ((double)data->t)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(test, test_range_minus_two_til_five_width_and_precision)
{
	while(data->a < 5)
	{
		while (data->b < 5)
		{
			data->buff.expected_ret = printf("%*.*i, %*.*d, %*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_expected(&(data->buff));
			data->buff.actual_ret = ft_printf("%*.*i, %*.*d, %*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_actual(&(data->buff));
			ASSERT_STR(data->buff.expected, data->buff.actual);
			ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);

			data->buff.expected_ret = printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_expected(&(data->buff));
			data->buff.actual_ret = ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_actual(&(data->buff));
			ASSERT_STR(data->buff.expected, data->buff.actual);
			ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);


			data->buff.expected_ret = printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_expected(&(data->buff));
			data->buff.actual_ret = ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_actual(&(data->buff));
			ASSERT_STR(data->buff.expected, data->buff.actual);
			ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);

			data->buff.expected_ret = printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_expected(&(data->buff));
			data->buff.actual_ret = ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_actual(&(data->buff));
			ASSERT_STR(data->buff.expected, data->buff.actual);
			ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);

			data->buff.expected_ret = printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_expected(&(data->buff));
			data->buff.actual_ret = ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_actual(&(data->buff));
			ASSERT_STR(data->buff.expected, data->buff.actual);
			ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);

			data->buff.expected_ret = printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_expected(&(data->buff));
			data->buff.actual_ret = ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
			get_output_from_actual(&(data->buff));
			ASSERT_STR(data->buff.expected, data->buff.actual);
			ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
			data->b++;
		}
		data->a++;
	}
}

CTEST_DATA(random_imput)
{
	t_buff buff;
	int		a;
	int		b;
	char	c;
	int		d;
	int		e;
	int		f;
	int		g;
	int		h;
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	char	*n;
	char	*o;
	char	*p;
	char	*q;
	char	*r;
	char	*s;
	char	*t;
	char	*u;
	clock_t time;
	double time_taken;
};

CTEST_SETUP(random_imput)
{
	if( pipe(data->buff.pipe) != 0 )
    	exit(1);
	data->buff.saved_stdout_fd = dup(STDOUT_FILENO);
	dup2(data->buff.pipe[WRITE_PIPE], STDOUT_FILENO);
	close(data->buff.pipe[WRITE_PIPE]);
	data->a = -4;
	data->b = 0;
	data->c = 'a';
	data->d = 2147483647;
	data->e = -2147483648;
	data->f = 42;
	data->g = 25;
	data->h = 4200;
	data->i = 8;
	data->j = -12;
	data->k = 123456789;
	data->l = 0;
	data->m = -12345678;
	data->n = "abcdefghijklmnop";
	data->o = "-a";
	data->p = "-12";
	data->q = "0";
	data->r = "%%";
	data->s = "-2147483648";
	data->t = "0x12345678";
	data->u = "-0";
	data->time = clock();
}

CTEST_TEARDOWN(random_imput)
{
	dup2(data->buff.saved_stdout_fd, STDOUT_FILENO);  /* reconnect stdout for testing */
	data->time = clock() - data->time;
	data->time_taken = ((double)data->time)/CLOCKS_PER_SEC;
	// printf("[time %fs] ", data->time_taken);
}

CTEST2(random_imput, random_1)
{
	data->a = -2;
	data->buff.expected_ret = printf("%02.*d %02.*d, %02.*d, %02.*d\n", data->a, data->i, data->a, data->j, data->a, data->k, data->a, data->b);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%02.*d %02.*d, %02.*d, %02.*d\n", data->a, data->i, data->a, data->j, data->a, data->k, data->a, data->b);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_2)
{
	data->buff.expected_ret = printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", data->a, data->i, data->a, data->j, data->a, data->k, data->a, data->l, data->a, data->m, data->a, data->c, data->a, data->e, data->a, data->d);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", data->a, data->i, data->a, data->j, data->a, data->k, data->a, data->l, data->a, data->m, data->a, data->c, data->a, data->e, data->a, data->d);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_3)
{
	data->a = 1;
	data->buff.expected_ret = printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_4)
{
	data->a = 1;
	data->buff.expected_ret = printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_5)
{
	data->a = 1;
	data->buff.expected_ret = printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", data->a, data->b, data->i, data->a, data->b, data->j, data->a, data->b, data->k, data->a, data->b, data->l, data->a, data->b, data->m, data->a, data->b, data->c, data->a, data->b, data->e, data->a, data->b, data->d);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_6)
{
	// hardcoded output because of linux
	data->buff.expected_ret = printf("%p, %x, %p, %x, %p, %x, 0x0, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, 0);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_7)
{
	data->a = 12;
	data->b = 18;
	data->buff.expected_ret = printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", data->c, data->n[0], data->o[0], data->a, data->p[0], data->a, data->q[0], data->a, data->r[0], data->a, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", data->c, data->n[0], data->o[0], data->a, data->p[0], data->a, data->q[0], data->a, data->r[0], data->a, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}


CTEST2(random_imput, random_8)
{
	data->a = 12;
	data->b = 18;
	data->buff.expected_ret = printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", data->c, data->n[0], data->o[0], -(data->a), data->p[0], -(data->a), data->q[0], -(data->a), data->r[0], -(data->a), data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", data->c, data->n[0], data->o[0], -(data->a), data->p[0], -(data->a), data->q[0], -(data->a), data->r[0], -(data->a), data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_9)
{
	data->a = 12;
	data->b = 18;
	data->buff.expected_ret = printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", data->c, data->n[0], data->q[0], data->a, data->q[0], data->a, data->p[0], data->a, data->p[0], data->a, data->c);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", data->c, data->n[0], data->q[0], data->a, data->q[0], data->a, data->p[0], data->a, data->p[0], data->a, data->c);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_10)
{
	data->a = 12;
	data->buff.expected_ret = printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, data->a, -12, data->a, -1, data->a, -255);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, data->a, -12, data->a, -1, data->a, -255);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_11)
{
	data->a = 12;
	data->b = 18;
	data->buff.expected_ret = printf("%%, \t, \\, \", \', +\n");
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%%, \t, \\, \", \', +\n");
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_12)
{
	data->buff.expected_ret = printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@\n", data->h, "bada", data->r, data->p, data->r, data->r, data->i, data->r, data->i, data->r, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@\n", data->h, "bada", data->r, data->p, data->r, data->r, data->i, data->r, data->i, data->r, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_13)
{
	data->buff.expected_ret = printf("%s**-d%%0*d%-12s0*@\n", data->r, data->p, data->r, data->r, data->i, data->r, data->i, data->r, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%s**-d%%0*d%-12s0*@\n", data->r, data->p, data->r, data->r, data->i, data->r, data->i, data->r, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_14)
{
	data->buff.expected_ret = printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", data->a, data->i, data->a, data->i, data->a, data->i, data->a, data->i, data->a, data->i);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", data->a, data->i, data->a, data->i, data->a, data->i, data->a, data->i, data->a, data->i);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_15)
{
	data->buff.expected_ret = printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", data->a, data->j, data->a, data->j, data->a, data->j, data->a, data->j, data->a, data->j);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", data->a, data->j, data->a, data->j, data->a, data->j, data->a, data->j, data->a, data->j);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_16)
{
	data->buff.expected_ret = printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", data->a, data->l, data->a, data->l, data->a, data->l, data->a, data->l, data->a, data->l);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", data->a, data->l, data->a, data->l, data->a, data->l, data->a, data->l, data->a, data->l);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_17)
{
	data->buff.expected_ret = printf("%i, %d, %d, %d, %d, %d, %u, %x, %X\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, %X\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_18)
{
	data->buff.expected_ret = printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X\n", data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X\n", data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0, data->a, 0);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_19)
{
	data->buff.expected_ret = printf("%c%-c%12c%-3c%-1c%1c%-2c%-4c%5c%3c%-*c%-*c%*c%*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%c%-c%12c%-3c%-1c%1c%-2c%-4c%5c%3c%-*c%-*c%*c%*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_20)
{
	//hardcoded because of linux
	data->buff.expected_ret = printf("(null)(null)(nul(null)  (null)  (null)(null)(null)((n(nul(null)");
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%-2s%.s%-4s%-2.4s%-8.12s%3s%8s%---2s%.*s%.0s%.1s%.2s%.4s%.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_21)
{
	data->buff.expected_ret = printf("(null)\n");
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("(null)\n");
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}


CTEST2(random_imput, random_22)
{
	data->buff.expected_ret = printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_23)
{
	data->buff.expected_ret = printf("a%db%dc%dd", 1, -2, 3);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%db%dc%dd", 1, -2, 3);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_24)
{
	data->buff.expected_ret = printf("a%ib%ic%id", 1, -2, 3);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%ib%ic%id", 1, -2, 3);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_25)
{
	data->buff.expected_ret = printf("a%ub%uc%ud", 0, 55555, 100000);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%ub%uc%ud", 0, 55555, 100000);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_26)
{
	data->buff.expected_ret = printf("a%xb%xc%xd", 0, 55555, 100000);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%xb%xc%xd", 0, 55555, 100000);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_27)
{
	data->buff.expected_ret = printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}


CTEST2(random_imput, random_28)
{
	data->buff.expected_ret = printf("a%db%dc%dd", 1, -2, 3);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%db%dc%dd", 1, -2, 3);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_29)
{
	data->buff.expected_ret = printf("a%ib%ic%id", 1, -2, 3);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%ib%ic%id", 1, -2, 3);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_30)
{
	data->buff.expected_ret = printf("a%ub%uc%ud", 0, 55555, 100000);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%ub%uc%ud", 0, 55555, 100000);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_31)
{
	data->buff.expected_ret = printf("a%dx%uc%ud", 0, 55555, 100000);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%dx%uc%ud", 0, 55555, 100000);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_32)
{
	data->buff.expected_ret = printf("a%dx%uu%ud", 0, 55555, 100000);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%dx%uu%ud", 0, 55555, 100000);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}

CTEST2(random_imput, random_33)
{
	data->buff.expected_ret = printf("a%dx%du%dd", 0, 55555, 100000);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("a%dx%du%dd", 0, 55555, 100000);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}


CTEST2(random_imput, random_34)
{
	data->buff.expected_ret = printf("%.3d", 0);
	get_output_from_expected(&(data->buff));
	data->buff.actual_ret = ft_printf("%.3d", 0);
	get_output_from_actual(&(data->buff));
	ASSERT_STR(data->buff.expected, data->buff.actual);
	ASSERT_EQUAL(data->buff.expected_ret, data->buff.actual_ret);
}
