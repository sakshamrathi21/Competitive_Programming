#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE	100

char forest[MAX_SIZE][MAX_SIZE];
int path[MAX_SIZE][MAX_SIZE];
int N, M, K;

void find_start_pos(int *x, int *y)
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (forest[i][j] == 'M') {
				*x = i;
				*y = j;
			}
}

int is_marked(int i, int j)
{
	return path[i][j];
}

void mark(int i, int j)
{
	path[i][j] = 1;
}

int get_move_options(int i, int j, int *up, int *down, int *left, int *right)
{
	int count = 0;

	*up = 0;
	*down = 0;
	*left = 0;
	*right = 0;

	if (i > 0 && forest[i - 1][j] != 'X' && !is_marked(i - 1, j)) {
		count++;
		*up = 1;
	}
	if (i < N - 1 && forest[i + 1][j] != 'X' && !is_marked(i + 1, j)) {
		count++;
		*down = 1;
	}
	if (j > 0 && forest[i][j - 1] != 'X' && !is_marked(i, j - 1)) {
		count++;
		*left = 1;
	}
	if (j < M - 1 && forest[i][j + 1] != 'X' && !is_marked(i, j + 1)) {
		count++;
		*right = 1;
	}

	return count;
}

int waves_count(int i, int j, int count)
{
	int up, down, left, right;
	int up_ok, down_ok, left_ok, right_ok;
	int new_count;

	mark(i, j);

	/* too many waves */
	if (count > K)
		return -1;

	/* exit found */
	if (forest[i][j] == '*' && count == K)
		return count;

	/* we have to use the wand */
	new_count = count;
	if (get_move_options(i, j, &up_ok, &down_ok, &left_ok, &right_ok) > 1)
		new_count++;

	/* up */
	if (up_ok) {
		up = waves_count(i - 1, j, new_count);
		if (up != -1)
			return up;
	}

	/* down */
	if (down_ok) {
		down = waves_count(i + 1, j, new_count);
		if (down != -1)
			return down;
	}

	/* left */
	if (left_ok) {
		left = waves_count(i, j - 1, new_count);
		if (left != -1)
			return left;
	}

	/* right */
	if (right_ok) {
		right = waves_count(i, j + 1, new_count);
		if (right != -1)
			return right;
	}

	return -1;
}

int main()
{
	int T;
	int i, j, k;
	int x, y, count;

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		for (j = 0; j < N; j++)
			for (k = 0; k < M; k++)
				scanf(" %c", &forest[j][k]);
		scanf("%d", &K);

		memset(path, 0, sizeof(path));
		find_start_pos(&x, &y);
		count = waves_count(x, y, 0);
		if (count == K)
			printf("Impressed\n");
		else
			printf("Oops!\n");
	}

	return 0;
}