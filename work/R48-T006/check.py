#!/usr/bin/env python3
"""R48-T006: check the triangle exercise implementations.

This script builds temporary copies of the triangle exercise and runs the test suite
against three variants:
  1. Learner stub (example.c removed) – should fail to link.
  2. Reference implementation (original .meta/example.c) – should pass all tests.
  3. Alternative implementation (different representation) – should also pass all tests.

The script does not modify the repository working tree. Evidence (logs, tool
versions) is written under work/R48-T006/evidence/. Exit status is 0 only if all
checks succeed.
"""

import subprocess
import shutil
import sys
import hashlib
import json
import platform
import os
import re
from pathlib import Path

# Paths (artifact location is separate from workspace)
ARTIFACT_ROOT = Path(__file__).resolve().parent
REPO_ROOT = Path("/Users/shiv/Desktop/S&AI - Assessment (Open Source)/Task 6")  # workspace root
EXERCISE_REL = Path("exercises/practice/triangle")
EXERCISE = REPO_ROOT / EXERCISE_REL
CONFIG = json.load(open(EXERCISE / ".meta/config.json"))

# Resolve files from config
SOLUTION = EXERCISE / CONFIG["files"]["solution"][0]
TEST = EXERCISE / CONFIG["files"]["test"][0]
EXAMPLE_C = EXERCISE / CONFIG["files"]["example"][0]
EXAMPLE_H = EXERCISE / CONFIG["files"]["example"][1]

EVIDENCE = ARTIFACT_ROOT / "evidence"
EVIDENCE.mkdir(parents=True, exist_ok=True)

def run(cmd, cwd=None, input_data=None):
    try:
        result = subprocess.run(
            cmd,
            cwd=cwd,
            input=input_data,
            text=True,
            capture_output=True,
            timeout=120,
        )
    except subprocess.TimeoutExpired:
        return 124, "", "timeout"
    return result.returncode, result.stdout, result.stderr

def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()

def hash_tree(root: Path) -> dict:
    return {str(p.relative_to(root)): sha256(p.read_bytes()) for p in root.rglob("*") if p.is_file()}

def write_evidence(name: str, content: str):
    (EVIDENCE / f"{name}.log").write_text(content)

def make_test(dir_path: Path):
    return run(["make", "test"], cwd=dir_path)

def check_variant(label: str, src_example: Path | None, expect_pass: bool):
    # Create a temporary working copy
    tmp = Path("/tmp") / f"triangle_{label}_{os.getpid()}"
    if tmp.exists():
        shutil.rmtree(tmp)
    shutil.copytree(EXERCISE, tmp)
    # Path to the implementation file in the temporary copy
    impl_path = tmp / "triangle.c"
    if src_example:
        # Use the provided source (reference or alternative) as implementation
        print(f"{label}: copying implementation from {src_example} to {impl_path}")
        shutil.copy2(src_example, impl_path)
    else:
        # Remove any existing implementation to simulate learner stub
        if impl_path.is_file():
            print(f"{label}: removing implementation {impl_path}")
            impl_path.unlink()
    ret, out, err = make_test(tmp)
    write_evidence(f"{label}_make_ret", str(ret))
    write_evidence(f"{label}_make_out", out)
    write_evidence(f"{label}_make_err", err)
    if expect_pass:
        if ret != 0:
            print(f"{label}: expected pass but exit {ret}")
            sys.exit(1)
        m = re.search(r"(\d+) Tests (\d+) Failures (\d+) Ignored", out)
        if not m:
            print(f"{label}: cannot parse summary")
            sys.exit(1)
        total, failures, ignored = map(int, m.groups())
        if failures != 0 or ignored != 0:
            print(f"{label}: failures {failures} or ignored {ignored}")
            sys.exit(1)
        print(f"{label}: passed {total} tests")
    else:
        if ret == 0:
            print(f"{label}: expected failure but succeeded")
            sys.exit(1)
        print(f"{label}: correctly failed with exit {ret}")
    shutil.rmtree(tmp)
    # Create a temporary working copy
    tmp = Path("/tmp") / f"triangle_{label}_{os.getpid()}"
    if tmp.exists():
        shutil.rmtree(tmp)
    shutil.copytree(EXERCISE, tmp)
    # Adjust example.c
    rel_example = EXAMPLE_C.relative_to(EXERCISE)
    target_example = tmp / rel_example
    if src_example:
        # Ensure parent directory exists (especially for .meta)
        target_example.parent.mkdir(parents=True, exist_ok=True)
        print(f"{label}: copying {src_example} to {target_example}")
        shutil.copy2(src_example, target_example)
    else:
        if target_example.is_file():
            print(f"{label}: removing reference {target_example}")
            target_example.unlink()
    ret, out, err = make_test(tmp)
    write_evidence(f"{label}_make_ret", str(ret))
    write_evidence(f"{label}_make_out", out)
    write_evidence(f"{label}_make_err", err)
    if expect_pass:
        if ret != 0:
            print(f"{label}: expected pass but exit {ret}")
            sys.exit(1)
        m = re.search(r"(\d+) Tests (\d+) Failures (\d+) Ignored", out)
        if not m:
            print(f"{label}: cannot parse summary")
            sys.exit(1)
        total, failures, ignored = map(int, m.groups())
        if failures != 0 or ignored != 0:
            print(f"{label}: failures {failures} or ignored {ignored}")
            sys.exit(1)
        print(f"{label}: passed {total} tests")
    else:
        if ret == 0:
            print(f"{label}: expected failure but succeeded")
            sys.exit(1)
        print(f"{label}: correctly failed with exit {ret}")
    shutil.rmtree(tmp)
    # Create a temporary working copy
    tmp = Path("/tmp") / f"triangle_{label}_{os.getpid()}"
    if tmp.exists():
        shutil.rmtree(tmp)
    shutil.copytree(EXERCISE, tmp)
    # Adjust example.c
    rel_example = EXAMPLE_C.relative_to(EXERCISE)
    target_example = tmp / rel_example
    target_example.parent.mkdir(parents=True, exist_ok=True)
    if src_example:
        shutil.copy2(src_example, target_example)
    else:
        if target_example.is_file():
            target_example.unlink()
    ret, out, err = make_test(tmp)
    write_evidence(f"{label}_make_ret", str(ret))
    write_evidence(f"{label}_make_out", out)
    write_evidence(f"{label}_make_err", err)
    if expect_pass:
        if ret != 0:
            print(f"{label}: expected pass but exit {ret}")
            sys.exit(1)
        m = re.search(r"(\d+) Tests (\d+) Failures (\d+) Ignored", out)
        if not m:
            print(f"{label}: cannot parse summary")
            sys.exit(1)
        total, failures, ignored = map(int, m.groups())
        if failures != 0 or ignored != 0:
            print(f"{label}: failures {failures} or ignored {ignored}")
            sys.exit(1)
        print(f"{label}: passed {total} tests")
    else:
        if ret == 0:
            print(f"{label}: expected failure but succeeded")
            sys.exit(1)
        print(f"{label}: correctly failed with exit {ret}")
    shutil.rmtree(tmp)

def main():
    # Record tool versions
    versions = []
    for tool in ["gcc", "clang", "make", "python3"]:
        ret, out, _ = run([tool, "--version"])
        versions.append(out.splitlines()[0])
    (EVIDENCE / "tool_versions.txt").write_text("\n".join(versions))

    # 1. Learner stub (no example.c)
    check_variant("stub", None, expect_pass=False)

    # 2. Reference implementation (original example.c)
    check_variant("reference", EXAMPLE_C, expect_pass=True)

    # 3. Alternative implementation – write temporary file then test
    alt_code = '''#include "triangle.h"\n#include <stdbool.h>\n\nstatic bool valid(triangle_t s) {\n    return s.a > 0 && s.b > 0 && s.c > 0 &&\n           s.a + s.b >= s.c &&\n           s.a + s.c >= s.b &&\n           s.b + s.c >= s.a;\n}\n\nbool is_equilateral(triangle_t sides) {\n    if (!valid(sides)) return false;\n    return sides.a == sides.b && sides.b == sides.c;\n}\n\nbool is_isosceles(triangle_t sides) {\n    if (!valid(sides)) return false;\n    return sides.a == sides.b || sides.b == sides.c || sides.a == sides.c;\n}\n\nbool is_scalene(triangle_t sides) {\n    if (!valid(sides)) return false;\n    return sides.a != sides.b && sides.b != sides.c && sides.a != sides.c;\n}\n'''
    alt_path = ARTIFACT_ROOT / "alt_example.c"
    alt_path.write_text(alt_code)
    check_variant("alternative", alt_path, expect_pass=True)
    alt_path.unlink()

    # Record hashes for audit (just placeholder hashes)
    (EVIDENCE / "hashes.json").write_text(json.dumps({"stub": "n/a"}, indent=2))

if __name__ == "__main__":
    main()
