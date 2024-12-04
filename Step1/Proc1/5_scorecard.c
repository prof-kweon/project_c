/**
 * 단계1 과정1 Problem 5
 */

/*
수행 문제
심사위원이 입력할 오디션 후보자 평가 시트는 7개의 요소를 갖는 “scoring_sheet” 배열을 구현한다.
- 후보위원 고유 ID와 음악 소양, 댄스, 보컬, 비주얼, 전달력이라는 5가지 분야의 점수(각 100점 만점), 총점(500점 만점)
후보자 배열  “candidates”을 정의하고 초기화한다.
- 후보자의 이름, 중복되지 않는 6자리 고유 ID.
심사위원 이름과 전문 분야를 입력받아 6명의 후보자에 대한 해당 분야 점수(10~100 점)를 입력하는 다음의 화면과 기능을 구현한다.
- 잘못된 값은 다시 입력받아야 한다.
####################################
#       오디션 심사 결과 입력       #
####################################
> 심사위원 이름: 김영수
> 전문 분야: 음악
++++++++++++++++++++++++++++++++++++
후보자: 박지연
음악 소양: 80
------------------------------------
후보자: Ethan Smith
음악 소양: 70
------------------------------------
............이하 생략...............
심사 결과를 모두 입력한 후 “입력을 모두 완료했습니다. 입력 내용을 검토하세요.” 메시지와 함께 모든 후보자의 점수를 출력한다.
“제출하시겠습니까?” 메시지를 출력한 후  ‘Y’나 ‘N’을 입력 받는다.
- Y: 다음 줄에 “***최종 제출을 완료했습니다.***”를 출력한다.
- N: 다시 처음 부터 입력하는 화면으로 돌아간다.
구현해야 할 기능 화면
++++++++++++++++++++++++++++++++++++
입력을 모두 완료했습니다.
입력하신 내용을 검토하세요!
------------------------------------
박지연: 80
Ethan Smith: 70
............. 이하 생략 ............
제출하시겠습니까? Y
***최종 제출을 완료했습니다.***
>
(보너스) “제출하시겠습니까?”에 대해 N을 입력할 경우 후보자와 고유 ID를 입력해 후보자의 점수를 수정한다.
더 이상 수정할 후보자가 없는 경우 프로그램을 종료한다.
모든 심사위원의 입력이 끝나면 총점을 자동 계산해 점수 순으로 4명의 최종 멤버를 선발한다.
구현해야 할 기능 화면
=======================================
후보 선발 결과 집계 중 ...
=======================================
#######################################
# 밀리웨이즈의 멤버가 된 걸축하합니다!  #
#######################################
1. 박지연
2. Ethan Smith
3. Helena Silva
4. Liam Wilson

>
제약 사항
문제3의 후보자 기초 정보와 문제4의 심사위원 기초 정보를 사용한다.
솔루션 코드는 scorecard.c 파일에 작성한다.
모든 배열은 1차원이다.
심사위원이 평가 시트에서 참조할 후보자의 이름과 고유 ID를 담은 “candidates” 배열을 사용한다.
- 고유 ID는 중복되지 않는 6 자리 임의 정수 값이다.
심사위원이 입력할 오디션 후보자 평가 시트는 7개의 요소를 갖는 “scoring_sheet” 배열을 사용한다.
- 배열의 첫 번째 요소는 candidates 배열에서 가져온다.
- 배열의 마지막 요소는 자동으로 계산된 총점으로 채운다.
표준 라이브러리는 stdio.h와 stdlib.h만 사용한다. 
보너스 평가 가이드
“제출하시겠습니까?”에 대해 N을 입력할 경우 동작을 확인한다.
후보자와 고유 ID를 나열하고, 6자리 고유 ID 입력의 유효성을 처리하는지 확인한다. 
해당 후보자의 점수를 수정할 수 있는지 확인한다. 
수정할 후보자를 계속 입력할 수 있는지 확인한다.
더 이상 수정할 후보자가 없는 경우 프로그램을 종료하는지 확인다.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 6
#define MIN_SCORE 10
#define MAX_SCORE 100
#define NUM_FIELDS 5

// 후보자 구조체
typedef struct {
    char name[50];
    int id;
} Candidate;

// 평가 시트 구조체
typedef struct {
    int id;
    int scores[NUM_FIELDS]; // 음악 소양, 댄스, 보컬, 비주얼, 전달력 점수
    int total_score;        // 총점
} ScoringSheet;

// 후보자 배열
Candidate candidates[MAX_CANDIDATES] = {
    {"박지연", 123456},
    {"Ethan Smith", 234567},
    {"Helena Silva", 345678},
    {"Liam Wilson", 456789},
    {"Karolina Nowak", 567890},
    {"Suphanan Wong", 678901}
};

// 평가 시트 배열
ScoringSheet scoring_sheet[MAX_CANDIDATES];

// 점수 입력 함수
void input_scores(const char *judge_name, const char *specialty) {
    printf("####################################\n");
    printf("#       오디션 심사 결과 입력       #\n");
    printf("####################################\n");
    printf("> 심사위원 이름: %s\n", judge_name);
    printf("> 전문 분야: %s\n", specialty);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("후보자: %s\n", candidates[i].name);
        printf("%s: ", specialty);

        int score;
        while (1) {
            scanf("%d", &score);
            if (score >= MIN_SCORE && score <= MAX_SCORE) {
                scoring_sheet[i].scores[0] = score; // 첫 번째 항목 점수
                break;
            }
            printf("점수는 %d에서 %d 사이여야 합니다. 다시 입력하세요: ", MIN_SCORE, MAX_SCORE);
        }
        printf("------------------------------------\n");
    }
}

// 총점 계산 함수
void calculate_totals() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        scoring_sheet[i].total_score = 0;
        for (int j = 0; j < NUM_FIELDS; j++) {
            scoring_sheet[i].total_score += scoring_sheet[i].scores[j];
        }
    }
}

// 점수 출력 함수
void print_scores() {
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("입력을 모두 완료했습니다.\n");
    printf("입력하신 내용을 검토하세요!\n");
    printf("------------------------------------\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d\n", candidates[i].name, scoring_sheet[i].scores[0]);
    }
    printf("------------------------------------\n");
}

// 점수 수정 함수
void modify_scores() {
    while (1) {
        printf("수정할 후보자의 고유 ID를 입력하세요 (종료하려면 0을 입력): ");
        int id, found = 0;
        scanf("%d", &id);

        if (id == 0) break;

        for (int i = 0; i < MAX_CANDIDATES; i++) {
            if (scoring_sheet[i].id == id) {
                found = 1;
                printf("후보자: %s\n", candidates[i].name);
                printf("새로운 점수를 입력하세요: ");

                int score;
                while (1) {
                    scanf("%d", &score);
                    if (score >= MIN_SCORE && score <= MAX_SCORE) {
                        scoring_sheet[i].scores[0] = score;
                        printf("점수가 수정되었습니다.\n");
                        break;
                    }
                    printf("점수는 %d에서 %d 사이여야 합니다. 다시 입력하세요: ", MIN_SCORE, MAX_SCORE);
                }
                break;
            }
        }
        if (!found) {
            printf("입력한 고유 ID를 가진 후보자를 찾을 수 없습니다.\n");
        }
    }
}

// 최종 선발 함수
void select_finalists() {
    calculate_totals();

    // 점수 순으로 후보자를 정렬
    for (int i = 0; i < MAX_CANDIDATES - 1; i++) {
        for (int j = i + 1; j < MAX_CANDIDATES; j++) {
            if (scoring_sheet[i].total_score < scoring_sheet[j].total_score) {
                ScoringSheet temp = scoring_sheet[i];
                scoring_sheet[i] = scoring_sheet[j];
                scoring_sheet[j] = temp;
            }
        }
    }

    // 최종 결과 출력
    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");
    printf("#######################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸 축하합니다! #\n");
    printf("#######################################\n");
    for (int i = 0; i < 4; i++) { // 상위 4명 출력
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// 메인 함수
int main() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        scoring_sheet[i].id = candidates[i].id; // 고유 ID 초기화
        for (int j = 0; j < NUM_FIELDS; j++) {
            scoring_sheet[i].scores[j] = 0; // 점수 초기화
        }
        scoring_sheet[i].total_score = 0;
    }

    char judge_name[50], specialty[50], submit_choice;

    while (1) {
        printf("> 심사위원 이름: ");
        scanf("%s", judge_name);

        printf("> 전문 분야: ");
        scanf("%s", specialty);

        input_scores(judge_name, specialty);

        print_scores();

        printf("제출하시겠습니까? (Y/N): ");
        scanf(" %c", &submit_choice);

        if (submit_choice == 'Y' || submit_choice == 'y') {
            printf("***최종 제출을 완료했습니다.***\n");
            break;
        } else if (submit_choice == 'N' || submit_choice == 'n') {
            modify_scores();
        }
    }

    select_finalists();

    return 0;
}

/*
코드 설명
구조체 정의

Candidate: 후보자의 이름과 고유 ID를 저장.
ScoringSheet: 고유 ID, 각 분야 점수, 총점을 저장.
주요 함수

input_scores: 특정 전문 분야의 점수를 입력받아 저장.
calculate_totals: 각 후보자의 총점을 계산.
print_scores: 입력한 점수를 출력.
modify_scores: 특정 후보자의 점수를 수정.
select_finalists: 총점 기준으로 상위 4명을 선발.
보너스 구현

점수 수정 기능: N 입력 시 수정할 후보자를 선택해 점수를 변경.
최종 선발: 총점을 기준으로 상위 4명을 출력.
제약 조건 준수

stdio.h와 stdlib.h만 사용.
모든 배열은 1차원 배열.
*/