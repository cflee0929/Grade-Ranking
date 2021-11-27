#include <iostream>
#include <time.h>

using namespace std;

typedef struct Score{
    int id;
    int chinese;
    int english;
    int math;
    int science;
    int society;
    double sum;
}score;

void input_score(int n, score *s);
void output_score(int n, score *s);
void sort_score(int n, score *s);


int main(){
    score *class_score, *sorted_class_score;
    int n, op;
    cout << "=== 班級成績排名 ===" << endl << "請輸入班級人數: ";
    cin >> n;
    class_score = new score[n]; /*記憶體配置*/
    sorted_class_score = new score[n]; /*記憶體配置*/

    input_score(n, class_score);
    for(int i=0;i<n;i++){
        *(sorted_class_score+i) = *(class_score+i);
    }

    while(1){
        cout << "(1)查看班級成績(依學號排序)" << endl;
        cout << "(2)查看班級成績(依成績排序)" << endl;
        cout << "(3)查看前三名" << endl;
        cout << "(4)離開" << endl << ">";
        cin >> op;
        switch(op){
            case 1:
                output_score(n, class_score);
                break;
            case 2:
                sort_score(n, sorted_class_score);
                output_score(n, sorted_class_score);
                break;
            case 3:
                output_score(3, sorted_class_score);
                break;
            case 4:
                delete []class_score;
                delete []sorted_class_score;
                return 0;
        }
        system("pause");
        system("cls");
    }

    delete []class_score;
    delete []sorted_class_score;
    return 0;
}


void input_score(int n, score *s){
    srand(time(NULL));

    for(int i=0;i<n;i++){
        (s+i)->id = i;
        /*分數隨機亂數*/
        (s+i)->chinese = rand()%100+1;
        (s+i)->english = rand()%100+1;
        (s+i)->math = rand()%100+1;
        (s+i)->science = rand()%100+1;
        (s+i)->society = rand()%100+1;
        (s+i)->sum = (s+i)->chinese + (s+i)->english + (s+i)->math + (s+i)->science + (s+i)->society;
    }
}

void output_score(int n, score *s){
    for(int i=0;i<n;i++){
        cout << "學號: " << (s+i)->id+1 << endl;
        cout << "國文: " << (s+i)->chinese << endl;
        cout << "英文: " << (s+i)->english << endl;
        cout << "數學: " << (s+i)->math << endl;
        cout << "自然: " << (s+i)->science << endl;
        cout << "社會: " << (s+i)->society << endl;
        cout << "平均: " << (s+i)->sum/5 << endl;
        cout << "==========" << endl;
    }
}

void sort_score(int n, score *s){
    score temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if((s+j)->sum < (s+j+1)->sum){
                temp = *(s+j+1);
                *(s+j+1) = *(s+j);
                *(s+j) = temp;
            }
        }
    }
}
