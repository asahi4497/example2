#include <stdio.h>
#include <time.h>
#include <iostream>
#include <chrono>

double timer(clock_t start)
{
    // clock_t start = clock();
    //clock_t start;

    // 何かの処理

    clock_t end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("time %lf[ms]\n", time);
    return time;
}
/*
int main()
{
    clock_t start = clock();
    while (true)
    {
        //  std::cout << "          " << std::endl;
        double time = timer(start);
        if (time > 1000)
        {
            printf("time %lf[ms]\n", time);
            break;
        }
    }
    return 0;
}*/

double timer(std::chrono::system_clock::time_point start)
{
    std::chrono::system_clock::time_point end;
    end = std::chrono::system_clock::now();                                                      // 計測終了時間
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
    return elapsed;
}
void enemy(double flame, int enemynumber)
{
    for (int pos = 100; (flame - enemynumber) < pos; pos--)
    {
        std::cout << " ";
    }
    std::cout << "*";
}

int main()
{
    std::chrono::system_clock::time_point start; // 型は auto で可
    start = std::chrono::system_clock::now();    // 計測開始時間

    double sec = 1;
    int flame = 1;
    // 処理
    while (true)
    {
        flame = 0;

        while (true)
        {
            double time = timer(start);
            if (time > (sec * 100.0)) //sec *1000で1秒
            {
                //terminal は63行。63行以上を1面として更新していく
                for (int i = 0; i < 62; i++)
                {
                    std::cout << "          " << std::endl;
                }
                enemy(flame, 0);
                // enemy(flame, 2);
                std::cout << std::endl;
                /*int input;
                std::cin >> input;*/
                std::cout << "     ¥¥" << std::endl;
                std::cout << "     ¥¥" << std::endl;
                //////地面の決定
                for (int base = 0; base < 100; base++)
                {
                    std::cout << "_";
                }
                std::cout << std::endl;
                // printf("time %lf[ms]\n", time);
                sec++;
                flame++;
            }
            if (flame == 100)
                break;
        }
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
//-----------------------------------------------------------------
char *mygetchar(int timeout);
//-----------------------------------------------------------------
int main()
{
    char *buf = mygetchar(500); // 5秒でタイムアウト
    printf("input char: %s\n", buf);
    return 0;
}
//-----------------------------------------------------------------

// タイムアウト付き文字入力

//-----------------------------------------------------------------
void mywait(int no)
{
    printf("timeout.\n");
}

char *mygetchar(int timeout)
{
    static char buf[256];
    struct sigaction sa;
    struct itimerval itimer;

    // シグナルハンドラの設定
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = mywait;

    //sa.sa_flags   = SA_RESTART; // if restart input
    if (sigaction(SIGALRM, &sa, NULL) != 0)
    {
        perror("sigaction");
        return 0;
    }

    // タイマーの設定
    //  itimer.it_value.tv_sec = itimer.it_interval.tv_sec = 0;         //timeout; // sec
    itimer.it_value.tv_usec = itimer.it_interval.tv_usec = timeout; // micro sec
    if (setitimer(ITIMER_REAL, &itimer, NULL) < 0)
    {
        perror("setitimer");
        return 0;
    }
    fgets(buf, 256, stdin);
    return buf;
}
*/

//gcc -lncurses game.cc  でコンパイル
/*
#include <curses.h>

int main(void)
{
    int i = 0;

    initscr();
    timeout(500);
    noecho();
    cbreak();
    while (1)
    {
        int c = getch();
        if (c == 'q')
        {
            break;
        }
        i++;
        move(i / 50, i % 50);

        printw("a");
    }
    endwin();
    return 0;
}
*/