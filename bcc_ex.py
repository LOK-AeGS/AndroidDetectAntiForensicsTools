#!/data/local/tmp/py/python3
import os
import time
import json
SCRIPT_PATH = "/data/local/tmp/trace.bt"     # bpftrace 스크립트 파일 경로
OUTPUT_PATH = "/data/local/tmp/trace.json"   # JSON 출력 파일

# 2) bpftrace 실행을 백그라운드로 띄웁니다.
#    - -f json: NDJSON 출력
cmd = f"./bpftools/bpftrace -f json {SCRIPT_PATH} > {OUTPUT_PATH} &"
ret = os.system(cmd)
if ret != 0:
    print("bpftrace 실행 실패:", ret)
    exit(1)

# 3) 잠시 대기 후 출력 파일을 파이썬으로 파싱
time.sleep(6)

# 4) JSON 결과 읽기
with open(OUTPUT_PATH, "r") as f:
    for line in f:
        line = line.strip()
        # JSON 객체가 아니면 건너뛴다
        if not (line.startswith("{") and line.endswith("}")):
            continue
        entry = json.loads(line)
        if entry.get("type") == "map":
            counts = entry["data"].get("@", {})
            print("=== 5초 간격 호출 횟수 ===")
            for comm, cnt in counts.items():
                print(f"{comm}: {cnt}")
