PURPLE="\e[1;95m"
RESET="\e[0m"
GREEN="\e[1;32m"
RED="\e[1;31m"
COLS=$(tput cols)


function print_big_banner()
{
	printf "${GREEN}%80s\n%80s\n" |tr " " "="
	figlet -c  $1
	printf "${GREEN}%80s\n%80s\n${RESET}" | tr " " "="
	sleep 1
}

function print_small_banner()
{
	echo ""
	printf "\n${PURPLE}%80s\n${RESET}" | tr " " "="
	printf "%*s" $[COLS/3,5] "				$1"
	printf "\n${PURPLE}%80s\n${RESET}" | tr " " "="
}

function check_the_norm()
{
	print_small_banner "NORM CHECK"
	if grep norminette src/*.c | grep Error: --color=always || norminette inc/*.h | grep Error: --color=always; then
		printf "\n\n${RED} NORME ERRORS =( ${RESET}\n\n"
	else
		printf "${GREEN} NORME IS OKAY =) ${RESET}\n\n"
	fi
}

make clean > /dev/null && make > /dev/null && make 2> ./tests/results/warnings.txt

print_big_banner "FT PRINTF TESTER"

if [[ $# < 1 ]]; then
    print_small_banner "ALL TESTS"
	./test
else
	for var in "$@"
	do
		print_small_banner "TESTIN $var FLAG"
		./test $var
	done
fi

make fclean > /dev/null

check_the_norm