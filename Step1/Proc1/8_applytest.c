/**
 * 단계1 과정1 Problem 8
 */


/*
수행 문제
인증 시험 응시 관리에 필요한 자료구조를 구현한다.
9가지 훈련 분야 데이터로 배열을 초기화한다.
응시 분야와 응시 날짜를 배열에 저장한다.
프로그램을 시작 시 훈련 시작 날짜(YYYYMMDD)를 입력 받아야 하며, 이후 다시 변경할 수 없다.
인증 분야를 선택하고 응시 날짜를 입력한다. 
- 9가지 분야의 훈련 프로그램 각각은 최소 30일 이후 부터 ~ 최대 100일 이내에 통과해야 한다. 
- 각 훈련 프로그램은 최소 30일 이후부터 팀원 모두는 함께 해당 분야 인증에 응시할 수 있다. 
- 제일 먼저 체력과 지식 단계 인증을 통과한 후, 자기관리와 팀워크 단계를 응시할 수 있으며, 이후의 단계는 순서와 상관 없이 응시할 수 있다.
-  응시 날짜(YYYYMMDD)를 입력하면 최소 훈련 기간을 확인한 후 가능 여부를 알려준다.
인증 시험 예약 결과를 출력한다.
(보너스) 현재 날짜를 기준으로 예약한 인증 시험 예약 일자가 도래하기 전 10일 전부터 인증 시험 일정을 리마인드해야 한다.
(보너스) 인증 시험 당일인 경우, 시험 장소(10개의 방 중에서 임의로 선택)를 표시한다.

제약 사항
코드는 applytest.c 파일에 작성한다.
코드에서 사용하는 모든 배열은 1차원이다.
9가지 훈련 분야에 대한 인증 시험을 제공한다.
체력, 지식, 자기관리, 팀워크, 한국어, 보컬, 댄스, 비주얼, 연기
표준 라이브러리는 stdio.h와 math.h만 사용한다.
포인터는 사용하지 않는다.
보너스 평가 가이드
프로그램을 실행하면 현재 날짜를 기준으로 예약한 인증 시험 예약 일자가 도래하기 전 10일 전 부터 인증 시험 일정을 표시하는지 확인한다.
프로그램 실행 시 현재 날짜를 기준으로 인증 시험 당일인 경우, 시험 장소(10개의 방 중에서 임의로 선택)를 출력하는지 확인한다.
*/

#include <stdio.h>
#include <stdlib.h> // Include this for rand()
#include <math.h>

#define MAX_FIELDS 9
#define MAX_TESTS 10

// 훈련 분야 초기화
const char fields[MAX_FIELDS][20] = {
    "체력", "지식", "자기관리", "팀워크", "한국어", "보컬", "댄스", "비주얼", "연기"
};

// 시험 예약 정보
char reservations[MAX_FIELDS][20];
int reservation_dates[MAX_FIELDS] = {0}; // YYYYMMDD 형식으로 저장
int training_start_date;

// 날짜 계산 함수 (YYYYMMDD 형식의 날짜 -> 총 일수)
int calculate_days(int date) {
    int year = date / 10000;
    int month = (date % 10000) / 100;
    int day = date % 100;

    // 월별 일수
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 윤년 체크
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_in_month[1] = 29;
    }

    // 총 일수 계산
    int total_days = year * 365 + day;
    for (int i = 0; i < month - 1; i++) {
        total_days += days_in_month[i];
    }

    return total_days;
}

// 날짜 차이 계산
int calculate_date_difference(int date1, int date2) {
    return calculate_days(date2) - calculate_days(date1);
}

// 랜덤 방 번호 생성
int generate_room_number() {
    return (rand() % MAX_TESTS) + 1; // 1 ~ 10
}

// 인증 시험 예약 함수
void reserve_test(int field_index, int test_date) {
    int min_days = 30;
    int max_days = 100;

    // 날짜 차이 계산
    int date_diff = calculate_date_difference(training_start_date, test_date);

    // 최소/최대 훈련 일수 확인
    if (date_diff < min_days || date_diff > max_days) {
        printf("훈련 시작일로부터 %d일 이후 ~ %d일 이내에만 응시할 수 있습니다.\n", min_days, max_days);
        return;
    }

    // 필수 선행 조건 체크
    if (field_index == 2 || field_index == 3) { // 자기관리 또는 팀워크
        if (reservation_dates[0] == 0 || reservation_dates[1] == 0) {
            printf("체력 및 지식 인증을 통과한 후에만 자기관리 및 팀워크 인증을 예약할 수 있습니다.\n");
            return;
        }
    }

    // 예약 저장
    reservation_dates[field_index] = test_date;
    snprintf(reservations[field_index], 20, "%s", fields[field_index]);
    printf("%s 분야 인증 시험이 %d로 예약되었습니다.\n", fields[field_index], test_date);
}

// 인증 시험 일정 출력
void print_schedule() {
    printf("\n=======================================\n");
    printf("          인증 시험 예약 결과           \n");
    printf("=======================================\n");

    for (int i = 0; i < MAX_FIELDS; i++) {
        if (reservation_dates[i] != 0) {
            printf("%s: %d\n", fields[i], reservation_dates[i]);
        }
    }
}

// 리마인더 확인
void check_reminder(int current_date) {
    for (int i = 0; i < MAX_FIELDS; i++) {
        if (reservation_dates[i] != 0) {
            int days_left = calculate_date_difference(current_date, reservation_dates[i]);
            if (days_left == 0) {
                int room = generate_room_number();
                printf("오늘은 %s 인증 시험일입니다! 시험 장소: %d번 방\n", fields[i], room);
            } else if (days_left > 0 && days_left <= 10) {
                printf("%s 인증 시험이 %d일 남았습니다.\n", fields[i], days_left);
            }
        }
    }
}

int main() {
    int current_date;

    printf("훈련 시작 날짜를 입력하세요 (YYYYMMDD): ");
    scanf("%d", &training_start_date);

    while (1) {
        printf("\n=======================================\n");
        printf("          인증 시험 응시 관리 시스템       \n");
        printf("=======================================\n");
        printf("1. 인증 시험 예약\n");
        printf("2. 인증 시험 일정 보기\n");
        printf("3. 리마인더 확인\n");
        printf("4. 종료\n");
        printf("선택: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n예약할 인증 분야를 선택하세요:\n");
                for (int i = 0; i < MAX_FIELDS; i++) {
                    printf("%d. %s\n", i + 1, fields[i]);
                }

                int field_index, test_date;
                printf("선택: ");
                scanf("%d", &field_index);

                if (field_index < 1 || field_index > MAX_FIELDS) {
                    printf("올바른 분야를 선택하세요.\n");
                    break;
                }

                printf("응시 날짜를 입력하세요 (YYYYMMDD): ");
                scanf("%d", &test_date);

                reserve_test(field_index - 1, test_date);
                break;

            case 2:
                print_schedule();
                break;

            case 3:
                printf("현재 날짜를 입력하세요 (YYYYMMDD): ");
                scanf("%d", &current_date);

                check_reminder(current_date);
                break;

            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;

            default:
                printf("올바른 옵션을 선택하세요.\n");
        }
    }

    return 0;
}

/*
버그 수정 필요

코드 설명
구조 및 초기화:

fields 배열에 9가지 훈련 분야를 저장합니다.
reservations 배열에 예약된 분야와 reservation_dates에 해당 시험 일자를 저장합니다.
날짜 계산:

calculate_days 함수는 날짜(YYYYMMDD)를 총 일수로 변환합니다.
calculate_date_difference 함수는 두 날짜의 차이를 계산합니다.
시험 예약:

reserve_test 함수에서 최소 30일, 최대 100일 조건과 선행 조건(체력, 지식 통과)을 확인합니다.
시험 일정 출력:

예약된 시험 일자를 리스트 형식으로 출력합니다.
리마인더:

check_reminder 함수는 현재 날짜를 기준으로 시험 일정이 10일 이내인지 확인하고, 당일 시험일 경우 임의의 방 번호를 출력합니다.
메뉴:

시험 예약, 일정 확인, 리마인더 확인, 프로그램 종료 기능을 제공합니다.
*/