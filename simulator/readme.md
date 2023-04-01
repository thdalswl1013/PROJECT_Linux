
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


🌟**add**<br><br>
![image2](https://user-images.githubusercontent.com/110325367/229280412-e2d35f90-a320-4cae-ac84-3815b82e0d38.png)

🌟**addi**<br><br>
![image2](https://user-images.githubusercontent.com/110325367/229280457-0ca75d24-8cf9-4265-991e-d8aeec16a81d.png)
![image2](https://user-images.githubusercontent.com/110325367/229280498-b67321bb-e777-4c8a-a98b-4981341702d0.png)


🌟**Id**<br><br>
![image3](https://user-images.githubusercontent.com/110325367/229280576-d87d7b1f-0067-43ca-9421-e38beb0eff5e.png)

🌟**sd**<br><br>
![image4](https://user-images.githubusercontent.com/110325367/229280611-b7edb61a-d4eb-4422-a316-98cc54cc37ee.png)


🌟**beq**<br><br>
![image5](https://user-images.githubusercontent.com/110325367/229280715-d9b28e7d-745d-4fba-9121-51c8f4c375cf.png)

🌟**jal**<br><br>
![image4](https://user-images.githubusercontent.com/110325367/229280772-5d071242-42c9-4c9e-aadf-9f1203e4d91a.png)


🌟**jalr**<br><br>
![image5](https://user-images.githubusercontent.com/110325367/229280808-eb7480cf-1248-4503-a5ac-a72e90f3d145.png)

