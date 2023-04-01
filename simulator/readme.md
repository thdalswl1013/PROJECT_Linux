
# RISC-V simulator

single cycle 프로그램을 리눅스 개발환경에서 직접 구현해보고자 하였다. 
* Instruction Fetch(IF): instruction 메모리 상의 명령어를 읽는 단계
* Instruction Decode(ID): 가져온 instruction을 해석하는 단계
* Execute(EX): 해석된 instruction을 바탕으로 계산을 하는 단계
* Memory(MEM): 데이터 메모리에 접근하는 단계
* Write back(WB): 메모리에 저장된 값을 읽어오는 단계

<br><br>

# 🌟IF(Instruction Fetch)
![image1](https://user-images.githubusercontent.com/110325367/229280302-f8d73cae-7aef-446f-b1eb-3413d8612915.png)


# 🌟add
add는 R-type의 연산자로, 레지스터값 두 개(rs1, rs2)를 더하여 또 다른 레지스터(rd)에 저
장하는 방법의 연산이다. add의 opcode는 0110011이고, 이를 10진수로 나타내면 51이다. 따
라서 opcode가 51이라면 EX에서 add 연산을 수행하도록 한다. Instruction에서 각 비트 별로 나눠서 위치에 맞춰서 피연산자 rs1과 rs2를 받아오고(ID), 
이 받아온 레지스터들을 EX 단계에서 둘이 더해준 후 temp에 저장을 해준다(EX). 이후, temp에 저장을 해준 연산 결과를 write back 단계에서 또 다른 레지스터(rd)에 저장을 해준
다(WB). 이때, add 연산에서는 메모리에 대한 접근이 불필요하다. 또한, x0은 레지스터 상에
서 상수 0으로 고정되어있기 때문에 x0에는 값이 들어가면 안된다. 따라서 결과 값을 저장할 
레지스터(rd)가 0이 아닌 경우에만 이러한 연산이 실행되고, 0인 경우에는 연산값이 저장되지 
않고 0이 된다. 아래 그림들은 add 연산에서 수행되는 ID, EX, WB 과정을 나타낸 코드이다.

![image2](https://user-images.githubusercontent.com/110325367/229280412-e2d35f90-a320-4cae-ac84-3815b82e0d38.png)

# 🌟addi
![image2](https://user-images.githubusercontent.com/110325367/229280457-0ca75d24-8cf9-4265-991e-d8aeec16a81d.png)
![image2](https://user-images.githubusercontent.com/110325367/229280498-b67321bb-e777-4c8a-a98b-4981341702d0.png)


# 🌟Id
![image3](https://user-images.githubusercontent.com/110325367/229280576-d87d7b1f-0067-43ca-9421-e38beb0eff5e.png)

# 🌟sd
![image4](https://user-images.githubusercontent.com/110325367/229280611-b7edb61a-d4eb-4422-a316-98cc54cc37ee.png)


# 🌟beq
![image5](https://user-images.githubusercontent.com/110325367/229280715-d9b28e7d-745d-4fba-9121-51c8f4c375cf.png)

# 🌟jal
![image4](https://user-images.githubusercontent.com/110325367/229280772-5d071242-42c9-4c9e-aadf-9f1203e4d91a.png)


# 🌟jalr
![image5](https://user-images.githubusercontent.com/110325367/229280808-eb7480cf-1248-4503-a5ac-a72e90f3d145.png)

