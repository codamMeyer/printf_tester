#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctest.h>

#define MAX_LEN 2048
#define READ_PIPE 0
#define WRITE_PIPE 1

#define ASSERT_BUFF(buff)\
	ASSERT_EQUAL(buff.expected_ret, buff.actual_ret); \
	ASSERT_STR(buff.expected, buff.actual);


typedef struct s_buff
{
	char expected[MAX_LEN+1];
	char actual[MAX_LEN+1];
	int expected_ret;
	int actual_ret;
	int pipe[2];
	int saved_stdout_fd;
}				t_buff;


static void get_output_from_expected(t_buff *buff)
{
	fflush(stdout);
	read(buff->pipe[READ_PIPE], buff->expected, MAX_LEN); /* read from pipe into buffer */

}

static void get_output_from_actual(t_buff *buff)
{
	fflush(stdout);
	read(buff->pipe[READ_PIPE], buff->actual, MAX_LEN); /* read from pipe into buffer */
}

#endif
