# cpp_gameoflife

## 프로그램 설명
2차원 격자로 구성된 프레임안에서 아래의 규칙을 적용하여

각 칸의 상태를 삶,죽음 두가지로만 표현된다.

## 규칙
매 순간 자신의 상태와 주변의 8개 픽셀의 상태를 기준으로 다음 생애의 상태가 결정된다.

### **현재 상태 : 다음 상태**

- 자신이 현재 살아 있고, 주변 픽셀이 1개 이하만 살아 있으면 : 죽음
- 자신이 현재 살아 있고, 주변 픽셀이 4개 이상이 살아 있으면 : 죽음 
- 자신이 현재 살아 있고, 주변 픽셀이 2~3개 살아 있으면 : 삶
- 자신이 현재 죽어 있고, 주변 픽셀이 3개 살아 있으면 : 삶

## 동작 설명
초기 시작 화면에서 사용자에게 프레임의 크기를 입력받는다.

사용자는 몇가지 특징적인 초기 형태 중 하나를 선택한다.

10세대까지의 변화 패턴이 출력된다.

## 제약사항
현실 세계를 2차원 격자로 축소시켜 표현하고 있기 때문에,

경계에 위치한 픽셀의 경우에는

마치 구의 형태처럼 이웃하는 경계가 맞닿아 있다고 가정한 채 구현한다.
