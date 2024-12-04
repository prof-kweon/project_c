/**
 * 단계1 과정1 Problem 9
 */


/*
수행 문제
팀 평균 통과 점수와 개인 최소 점수, 데뷔 점수 확인 기능을 enum과 switch 문으로 구현한다.
- 팀 평균 통과 점수와 개인 최소 점수 설정은 11점 만점을 기준으로 입력한다. 
- 자동으로 데뷔를 결정하는 탁월한 점수는 95~100점 사이 값을 설정한다. 
9가지 분야(체력, 지식, 자기관리, 팀워크, 한국어, 보컬, 댄스, 비주얼, 연기)에 대한 밀리웨이즈 멤버 별 점수를 입력 받아 배열로 저장해야 한다.
- 팀 평균 점수 계산에서 소수점 이하는 버린다.
- 멤버 중 한 사람이라도 최소 한 분야에서 최소 점수에 미달하는 점수를 입력하면 최소 점수를 안내하고, 팀 전체가 해당 분야를 재 응시하라는 메시지를 표시하고 프로그램을 종료한다.
평가 위원장이 9가지 분야의 점수를 모두 입력하고 나면 총점을 계산한다. 
- 총점의 최소 값으로 1점을 제공하며 9 가지 분야의 총점은 100점 만점이다.
(보너스)  총점에 따라  밀리웨이즈의 운명을 결정한다. 
- 탁월한 점수 이상: “축하합니다. 무대 데뷔가 결정되었습니다.”를 출력한다.
- 90점 이상 ~ 탁월한 점수: “데뷔 인증 팀의 평가 회의에서 최종 결정합니다.”를 출력한다.
- 80 ~ 90점 미만: “30일 이후에 통과 점수가 가장 낮은 {재 인증 분야 3가지}를 다시 응시하세요.”를 출력한다.

제약 사항
코드는 decision.c 파일에 작성한다.
코드에서 사용하는 모든 배열은 1차원이다.
9가지 훈련 분야에 대한 인증 시험을 제공한다.
체력, 지식, 자기관리, 팀워크, 한국어, 보컬, 댄스, 비주얼, 연기
작성한 코드에는 enum과 switch 구문이 포함된다.
표준 라이브러리는 stdio.h와 math.h만 사용한다.
포인터는 사용하지 않는다.
보너스 평가 가이드
9가지 분야의 총점 계산 결과에 따라 밀리웨이즈 운명의 메시지를 출력하는지 확인한다.
지정한 탁월한 점수 이상일 때 “축하합니다. 무대 데뷔가 결정되었습니다.”를 출력하는지 확인한다.
90점 이상 ~ 탁월한 점수 사이일 때 “데뷔 인증 팀의 평가 회의에서 최종 결정합니다.”를 출력하는지 확인한다.
80 ~ 90점 미만인 경우  “30일 이후에 통과 점수가 가장 낮은 {재 인증 분야 3가지}를 다시 응시하세요.”를 출력한다.
{재 인증 분야 3가지}를 9가지 인증 중 가장 점수가 낮은 순 3가지로 대체했는지 확인한다.
*/

#include <stdio.h>
#include <stdlib.h> // Include this for exit()
#include <math.h>

// 분야 정의
enum Fields {
    FITNESS, KNOWLEDGE, SELF_MANAGEMENT, TEAMWORK, KOREAN, VOCAL, DANCE, VISUAL, ACTING, NUM_FIELDS
};

// 분야 이름
const char *field_names[NUM_FIELDS] = {
    "체력", "지식", "자기관리", "팀워크", "한국어", "보컬", "댄스", "비주얼", "연기"
};

// 점수 입력 및 계산
void input_scores(int scores[NUM_FIELDS], int *total_score, int min_score) {
    *total_score = 0;

    for (int i = 0; i < NUM_FIELDS; i++) {
        printf("%s 점수를 입력하세요 (1~11): ", field_names[i]);
        scanf("%d", &scores[i]);

        // 최소 점수 확인
        if (scores[i] < min_score) {
            printf("%s 점수가 최소 점수(%d점)에 미달합니다. 팀 전체가 해당 분야를 재응시해야 합니다.\n", field_names[i], min_score);
            printf("프로그램을 종료합니다.\n");
            exit(0);
        }

        *total_score += scores[i];
    }
}

// 재응시 분야 3가지 출력
void print_retest_fields(int scores[NUM_FIELDS]) {
    int lowest_indices[3] = {-1, -1, -1};
    int lowest_scores[3] = {100, 100, 100};

    for (int i = 0; i < NUM_FIELDS; i++) {
        if (scores[i] < lowest_scores[0]) {
            lowest_scores[2] = lowest_scores[1];
            lowest_indices[2] = lowest_indices[1];

            lowest_scores[1] = lowest_scores[0];
            lowest_indices[1] = lowest_indices[0];

            lowest_scores[0] = scores[i];
            lowest_indices[0] = i;
        } else if (scores[i] < lowest_scores[1]) {
            lowest_scores[2] = lowest_scores[1];
            lowest_indices[2] = lowest_indices[1];

            lowest_scores[1] = scores[i];
            lowest_indices[1] = i;
        } else if (scores[i] < lowest_scores[2]) {
            lowest_scores[2] = scores[i];
            lowest_indices[2] = i;
        }
    }

    printf("30일 이후에 통과 점수가 가장 낮은 %s, %s, %s 분야를 다시 응시하세요.\n",
           field_names[lowest_indices[0]],
           field_names[lowest_indices[1]],
           field_names[lowest_indices[2]]);
}

// 데뷔 결정
void decide_debut(int total_score, int excellent_score) {
    int team_score = total_score * 100 / (NUM_FIELDS * 11); // 팀 점수 계산 (백분율)
    printf("\n팀 평균 점수: %d점\n", team_score);

    switch (team_score) {
        case 95 ... 100:
            printf("축하합니다. 무대 데뷔가 결정되었습니다.\n");
            break;
        case 90 ... 94:
            printf("데뷔 인증 팀의 평가 회의에서 최종 결정합니다.\n");
            break;
        case 80 ... 89:
            printf("30일 이후에 통과 점수가 가장 낮은 3가지 분야를 다시 응시하세요.\n");
            break;
        default:
            printf("팀 점수가 부족하여 데뷔를 진행할 수 없습니다. 더 많은 훈련이 필요합니다.\n");
            break;
    }
}

int main() {
    int scores[NUM_FIELDS];
    int total_score = 0;
    int min_score, excellent_score;

    // 최소 점수 및 탁월한 점수 설정
    printf("팀 평균 통과 점수를 설정하세요 (1~11): ");
    scanf("%d", &min_score);
    printf("탁월한 점수를 설정하세요 (95~100): ");
    scanf("%d", &excellent_score);

    if (min_score < 1 || min_score > 11 || excellent_score < 95 || excellent_score > 100) {
        printf("잘못된 점수 입력입니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    // 점수 입력
    printf("\n9가지 분야에 대해 점수를 입력하세요.\n");
    input_scores(scores, &total_score, min_score);

    // 총점 확인
    total_score = fmax(total_score, 1); // 최소 총점 1점 보장

    // 데뷔 결정
    decide_debut(total_score, excellent_score);

    // 80 ~ 90점 미만일 경우 재응시 분야 출력
    int team_score = total_score * 100 / (NUM_FIELDS * 11);
    if (team_score >= 80 && team_score < 90) {
        print_retest_fields(scores);
    }

    return 0;
}

/*
코드 설명
구조 및 초기화:

enum으로 9가지 훈련 분야 정의.
field_names 배열에 분야 이름 저장.
점수 입력:

input_scores 함수에서 각 분야의 점수를 입력받고, 최소 점수 미달 시 프로그램 종료.
총점 계산:

총점을 계산하여 최소 1점을 보장.
decide_debut 함수에서 팀 평균 점수를 계산하고, switch 문으로 데뷔 결과 출력.
재응시 분야:

print_retest_fields 함수는 가장 낮은 점수를 가진 3가지 분야를 찾아 출력.
데뷔 결과 결정:

탁월한 점수 이상 (95~100): "축하합니다. 무대 데뷔가 결정되었습니다."
90~94점: "데뷔 인증 팀의 평가 회의에서 최종 결정합니다."
80~89점: "30일 이후에 통과 점수가 가장 낮은 3가지 분야를 다시 응시하세요."
80점 미만: "팀 점수가 부족하여 데뷔를 진행할 수 없습니다."
*/