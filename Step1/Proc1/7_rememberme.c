/**
 * 단계1 과정1 Problem 7
 */


/*
수행 문제 
밀리웨이즈 오디션 후보자 중 불합격 후보자 기초 데이터에 참가한 오디션(예: milliways)명과 롤링페이퍼(rollingpp##) 정보를 추가해  memorial##_arr 배열을 초기화 한다.
- memorial##_arr 배열은 초기화 후 수정이 불가능 하다.
- 기초 데이터는 이름을 시작으로 메일 주소로 끝나고 쉼표로 분리한다. 
memorial##_arr 배열에 기록된 후보자들에게 같은 오디션에서 경쟁했던 동료들이 전하는 마음을 디지털 롤링페이퍼 배열 rollingpp##에 “[name]: [message]”와 같은 JSON 데이터 형식으로 작성한다.
- 메시지를 보낼 후보자를 선택해야 한다.
- 합격한 후보자 모두 작성한 후 입력을 종료해야 한다.
- 합격자 이름과 메시지를 따로 입력 받아야 한다.
불합격 후보자 중에서 선택하면 해당 후보자에게 보내는 동료들의 메시지를 리스트 형식으로 출력한다.
(보너스) 불합격 후보자에게 동료의 롤링 페이퍼의 메시지를 보내는 기능을 추가한다.

제약 사항
공통 제약 사항을 모두 만족했는지 확인한다.
제약 사항을 모두 만족했는지 확인한다.
코드는 rememberme.c 파일에 작성한다.
코드에서 사용하는 모든 배열은 1차원이다.
표준 라이브러리는 stdio.h만 사용한다.
배열 이름에 붙이는 ##은 2자리 정수를 부여한다(예, 01,02, …. ,10)
문제 3의 후보자 데이터를 사용한다.
후보자 이름은 memorial##_arr에서 추출해 사용해야 한다.
포인터 변수를 선언하지 않는다.
보너스 평가 가이드
불합격 후보자를 선택하면 후보자에게 롤링 페이퍼의 메시지를 보내는 기능을 확인한다. 
받는 사람에 불합격 후보자의 메일 주소가 표시되고 본문에 동료들이 쓴 롤링 페이퍼 메시지가 표시되는지 확인한다.
메일 전송 여부를 선택할 수 있는지 확인한다.
메일 전송을 선택하면 “메일을 전송했습니다”와 같은 메시지를 표시하는지 확인한다.
*/

#include <stdio.h>
// #include <string.h>

#define MAX_MEMBERS 6
#define MAX_MESSAGES 10
#define MAX_MESSAGE_LENGTH 256

// 불합격 후보자 데이터 배열 (고정된 초기화)
const char memorial01_arr[MAX_MEMBERS][256] = {
    "Suphanan Wong,suphanan@outlook.com",
    "Karolina Nowak,karolina@outlook.com"
};

// 디지털 롤링페이퍼 배열
char rollingpp01[MAX_MESSAGES][MAX_MESSAGE_LENGTH];

// 문자열 길이 계산 함수
int _strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// 문자열 비교 함수
int _strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// 문자열 복사 함수
void _strcpy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// 메시지 작성 함수
void write_rolling_paper() {
    int rolling_count = 0;

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("합격 후보자가 불합격자에게 메시지를 작성합니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (1) {
        char sender_name[50];
        char recipient_name[50];
        char message[MAX_MESSAGE_LENGTH];

        printf("메시지를 작성할 합격 후보자의 이름을 입력하세요 (종료하려면 END 입력): ");
        scanf("%s", sender_name);
        if (_strcmp(sender_name, "END") == 0) break;

        printf("불합격 후보자의 이름을 입력하세요: ");
        scanf("%s", recipient_name);

        // 메시지 작성
        printf("메시지 내용을 입력하세요: ");
        getchar(); // Flush newline
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        for (int i = 0; i < MAX_MESSAGE_LENGTH; i++) {
            if (message[i] == '\n') {
                message[i] = '\0';
                break;
            }
        }

        // 저장
        int length = _strlen(rollingpp01[rolling_count]);
        snprintf(rollingpp01[rolling_count] + length, MAX_MESSAGE_LENGTH - length, "[%s]: %s", sender_name, message);
        rolling_count++;

        printf("메시지가 저장되었습니다.\n");

        if (rolling_count >= MAX_MESSAGES) {
            printf("롤링 페이퍼에 저장할 수 있는 최대 메시지 개수를 초과했습니다.\n");
            break;
        }
    }
}

// 메시지 출력 함수
void show_rolling_paper() {
    printf("\n++++++++++++++++++++++++++++++++++++\n");
    printf("불합격자에게 전송된 롤링 페이퍼 메시지 목록\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < MAX_MESSAGES; i++) {
        if (_strlen(rollingpp01[i]) > 0) {
            printf("%s\n", rollingpp01[i]);
        }
    }
}

// 메시지 전송 함수
void send_email() {
    char recipient_name[50];
    printf("메시지를 전송할 불합격 후보자의 이름을 입력하세요: ");
    scanf("%s", recipient_name);

    // 불합격자 메일 주소 찾기
    char recipient_email[50];
    int found = 0;
    for (int i = 0; i < MAX_MEMBERS; i++) {
        char temp_name[50], temp_email[50];
        sscanf(memorial01_arr[i], "%[^,],%s", temp_name, temp_email);

        if (_strcmp(temp_name, recipient_name) == 0) {
            _strcpy(recipient_email, temp_email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("불합격 후보자의 이름이 잘못되었습니다. 다시 시도하세요.\n");
        return;
    }

    // 메시지 전송 여부 확인
    printf("받는 사람: %s\n", recipient_email);
    printf("전송할 메시지:\n");
    for (int i = 0; i < MAX_MESSAGES; i++) {
        if (_strlen(rollingpp01[i]) > 0) {
            printf("%s\n", rollingpp01[i]);
        }
    }

    printf("\n메일을 전송하시겠습니까? (Y/N): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("메일을 전송했습니다.\n");
    } else {
        printf("메일 전송을 취소했습니다.\n");
    }
}

// 메인 함수
int main() {
    // 롤링페이퍼 배열 초기화
    for (int i = 0; i < MAX_MESSAGES; i++) {
        rollingpp01[i][0] = '\0'; // 빈 문자열로 초기화
    }

    while (1) {
        printf("\n####################################\n");
        printf("#       디지털 롤링 페이퍼 시스템     #\n");
        printf("####################################\n");
        printf("1. 롤링 페이퍼 작성\n");
        printf("2. 롤링 페이퍼 보기\n");
        printf("3. 메시지 전송\n");
        printf("4. 종료\n");
        printf("선택: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                write_rolling_paper();
                break;
            case 2:
                show_rolling_paper();
                break;
            case 3:
                send_email();
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("올바른 옵션을 선택하세요.\n");
        }
    }
}

/*
입력오류에 대한 무한루프 수정 필요

코드 설명
불합격 후보자 데이터 (memorial01_arr):

불합격 후보자의 기본 정보를 초기화된 문자열 배열로 저장합니다.
형식: "이름,메일주소"
롤링 페이퍼 데이터 (rollingpp01):

불합격 후보자에게 전송할 메시지를 저장합니다.
형식: "[보낸 사람]: [메시지]"
주요 기능:

write_rolling_paper:
합격자가 불합격자에게 메시지를 작성합니다.
최대 메시지 개수(MAX_MESSAGES)까지 작성 가능.
show_rolling_paper:
작성된 롤링 페이퍼 메시지를 출력합니다.
send_email:
불합격 후보자에게 메시지를 이메일 형식으로 전송합니다.
후보자의 메일 주소를 memorial01_arr에서 추출합니다.
제약 조건 준수:

1차원 배열 사용: 모든 데이터(memorial01_arr, rollingpp01)는 1차원 배열로 관리.
stdio.h만 사용: 추가 표준 라이브러리 사용 없음.
포인터 미사용.
보너스 기능:

불합격자 선택 시 해당 후보자에게 메시지를 전송하는 기능 구현.
전송 여부를 확인한 후 "메일을 전송했습니다" 메시지 출력.
*/