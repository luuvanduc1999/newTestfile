#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{
    struct pstat st;

    if(argc != 2){
        printf(1, "usage: mytest counter");
        exit();
    }

    int i, x, l, j;
    int mypid = getpid();
    
    #getpinfo lan dau de tim kiem vi tri cua mypid trong st, luu vao j
    getpinfo(&st);
    for (j = 0; j < NPROC; j++) {
        if (st.inuse[j] && st.pid[j] >= 3 && st.pid[j] == mypid) 
            break;
    }
    
    #lien tuc getpinfo va check tong s+=st.ticks[j][0,1,2,3] de xem da vuot qua tick nhap vao chua, neu roi thi xuat ticks trong tung hang doi ra ngoai
    while (1){
        getpinfo(&st);
        int s=0;
        for (l = 3; l >= 0; l--) 
            s+=st.ticks[j][l];
        if (s>=atoi(argv[1]))     {
            for (l = 3; l >= 0; l--) {
                printf(1, "level:%d \t ticks-used:%d\n", l, st.ticks[j][l]);
            }
            break;
        }

    }
   

    exit();
    return 0;
}
