# AndroidDetectAntiForensicsTools

### 실험 환경
A23 (루팅됨)

### ADB에서 추가적인 설정

bpftrace를 위한 환경변수 설정

export KBUILD_DIR=/path/kheaders

python을 위한 환경변수 설정

export PYTHONHOME=/path/python/lib

export PYTHONPATH=/path/python/lib/python3.10

### python 코드 실행

./python/bin/python3 bcc_ex.py

### 유의사항
실행할 때 bcc_ex.py 아래 bpftrace의 위치도 수정해줘야함.
