#!/bin/sh

set -eu

ROOT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)

make -C "$ROOT_DIR" CC=cc re >/dev/null

assert_contains() {
    haystack=$1
    needle=$2
    label=$3

    printf '%s\n' "$haystack" | grep -Fq "$needle" || {
        printf 'functional test failed: %s\n' "$label" >&2
        exit 1
    }
}

help_output=$("$ROOT_DIR/corewar" -h)
assert_contains "$help_output" "USAGE" "help header"
assert_contains "$help_output" "./corewar [-dump nbr_cycle]" "help usage line"

set +e
empty_output=$("$ROOT_DIR/corewar" 2>&1)
empty_status=$?
set -e

[ "$empty_status" -eq 0 ]
assert_contains "$empty_output" "error write in arena" "empty invocation"

set +e
dump_output=$("$ROOT_DIR/corewar" -dump 2>&1)
dump_status=$?
set -e

[ "$dump_status" -eq 0 ]
assert_contains "$dump_output" "error dump cycle missing" "missing dump value"