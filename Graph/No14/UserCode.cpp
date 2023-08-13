struct Pair {
    int first;
    int second;
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0 ,-1};
bool visited[10][10];
int board[10][10];
int result[10][10];
Pair queue[1000];
int rear, front;

void bfs_init(int map_size, int map[10][10]) {
    for (int i = 0; i < map_size; i++)
        for (int j = 0; j < map_size; j++)
            board[i][j] = map[i][j];
}
int bfs(int x1, int y1, int x2, int y2) {
    int i = y1 - 1;
    int j = x1 - 1;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            visited[i][j] = false;
            result[i][j] = 0;
        }
    }
   	visited[i][j] = true;
    
    front = 0, rear = 0;
    queue[rear++] = {i, j};
    
    while (front < rear)
    {
        int y = queue[front].first;
        int x = queue[front].second;
        front++;
        
    	for (int way = 0; way < 4; way++)
        {
            int yy = y + dy[way];
            int xx = x + dx[way];

            if (yy < 0 || xx < 0 || yy > 9 || xx > 9)	continue;

            if (board[yy][xx] != 1 && !visited[yy][xx])
            {
                result[yy][xx] = result[y][x] + 1;
                visited[yy][xx] = true;
                queue[rear++] = {yy, xx};
            }
        }
    }
    
    return result[y2-1][x2-1] == 0 ? -1 : result[y2-1][x2-1];
}
