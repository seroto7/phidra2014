#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* define the queue size. You can put bigger number here if the processing time is too small */
#define Q_MAX		10000
#define LOOP_MAX	1000

int queue[Q_MAX];
int last;

int put_q(int val)
{
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

	if (last > 0)
		--last;
	else {
		printf("Queue is empty\n");
		return -1;
	}

	/* this is the first way to avoid "FAKE FULL queue problem" */
	for (i = 0 ; i < last ; i++) {
		queue[i] = queue[i + 1];
	}

	return result;
}

int main()
{
	/* to select get_q or put_q */
	int put_or_get;
	/* to store the value to put in queue */
	int tmp;
	/* to measure the processing time */
	int start_time = 0, end_time = 0;

	/* below line will change the seed for random number */
	srand(time(NULL));

	/* keep the start time */
	start_time = time(NULL);

	while (LOOP_MAX) {
		/* 1/5 time will go to get_q and 4/5 time will go to put_q */
		put_or_get = rand()%5;

		if (put_or_get) {
		/* case : call the put_q */
			/* make the random number under 100 */
			tmp = rand()%100;
			printf("put value : %d\n", tmp);
			if (put_q(tmp)) {
				/* put_q returned error value (-1), full queue */
				/* quit the program */
				break;
			}
		} else {
		/* case : call the get_q */
			tmp = get_q();
			if (tmp < 0) {
				/* get_q returned error value (-1), empty queue */
				/* quit the program */
				break;
			}

			printf("get value : %d\n", tmp);
		}
	}

	end_time = time(NULL);

	printf("@@@@@ total time : %d\n", end_time - start_time);

	return 0;
}
