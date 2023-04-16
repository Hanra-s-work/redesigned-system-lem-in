/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** algo.c BFS
*/

int condition(int visited, int a, int j, int node)
{
    line_t *l;
    if (a[node][j] == 1 && visited[j] == 0) {
        my_put_nbr(j);
        visited[j] = 1;
        in_line_wait(l, j);
    }
}

int my_bfs(line_t *l)
{
    int node;
    int i = 0;
    int visited;
    int a;

    visited[i] = 1;
    in_line_wait(l, i);

    while (empty_line(l) == 0) {
        node = withdraw(l);
        for (int j = 0; j < 7; j++) {
            condition(visited, a, j, node);
        }
    }
}
