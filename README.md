# MFC-단일문서기반 펜만들기 팀프로젝트
### 개발환경 : visual studio 2022
### 팀장 : 권윤호
### 팀원 : 이재경 , 김성현
### 이론
MFC-SDI(단일문서기반) 구조 
 
SDI 프로그램 :   하나의 작업 윈도우만을 제공하는 프로그램 
 
생성클래스:  App, View, Doc(도큐먼트), Frame(툴바 등) 
 
Serialization(직렬화, 연속화) : 디스크 파일과 같은 영구 스토리지 매체에서 개체를 쓰거나 읽는 프로세스 
 
데이터를 저장하고 읽게 해준다.

## 개발과정
 
visual studio 새프로젝트 만들기-MFC앱-애플리케이션 종류(단일문서)-프로젝트 스타일(MFC Style)-파일 확장명 (anu) 
 
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/f7d019b9-cb77-42a3-a753-10a1f18b222a)

클래스뷰-cPenView-속성-MOUSEMOVE-OnMouseMove 
 
프로젝트-클래스마법사 - CLine클래스 생성 기본클래스는 CObject-CLine.h 생성

![image](https://github.com/gryrryfh/visual-programming/assets/50912987/70feb15d-112f-445a-bad4-cf11304870a9)

리소스뷰 - Menu - IDR_MAINFRAME - 색과 사이즈 꾸미기 
 
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/19a5ab54-eac9-4db4-82a6-576be983c5e6)

### 실행결과
 
https://github.com/gryrryfh/visual-programming/assets/50912987/7a804870-4cc5-4065-a316-11fb92a47cf4
