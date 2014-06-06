#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG
#define Q_MAX	100000

#if defined(DEBUG)
#define INFO	printf
#else
#define INFO
#endif

int queue[Q_MAX];
int last;

int put_q(int val)
{
	INFO("### put_q : value %d\n", val);
	INFO("### put_q : last %d\n", last);

	if (last >= Q_MAX) {
		printf("Queue is full, %d will be abandoned\n", val);
		return -1;
	} else {
		queue[last] = val;
		++last;
		return 0;
	}
}

int get_q(void)
{
	int result = queue[0];
	int i;

	INFO("### get_q : value %d\n", queue[0]);
	INFO("### get_q : last %d\n", last);

	if (last > 0)
		--last;
	else {
		printf("Queue is empty\n");
		return -1;
	}

	for (i = 0 ; i < last ; i++) {
		queue[i] = queue[i + 1];
	}

	return result;
}

int main()
{
	int put_or_get;
	int tmp;
	int get_cnt = 0, put_cnt = 0;
	int start_time = 0, end_time = 0;

	//srand(time(NULL));

	start_time = time(NULL);

	while (1000) {
		put_or_get = rand()%5;
		if (put_or_get) {
			put_cnt++;
			tmp = rand()%100;
			printf("put value : %d\n", tmp);
			if (put_q(tmp)) {
				printf("QUIT at put : %d %d\n", put_cnt, get_cnt);
				break;
			}
		} else {
			get_cnt++;
			tmp = get_q();
			if (tmp < 0) {
				printf("QUIT at get : %d %d\n", put_cnt, get_cnt);
				break;
			}

			printf("get value : %d\n", tmp);
		}
	}

	end_time = time(NULL);

	printf("@@@@@ total time : %d\n", end_time - start_time);

	return 0;
}
