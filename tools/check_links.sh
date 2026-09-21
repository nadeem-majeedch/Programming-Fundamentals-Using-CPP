#!/usr/bin/env bash
# tools/check_links.sh — verify relative markdown links resolve.
# Usage: bash tools/check_links.sh        (run from repository root)
# Exit:  0 = all links OK, 1 = broken link(s) found.

set -u

fail=0
checked=0

# repo root = parent of tools/
root="$(cd "$(dirname "$0")/.." && pwd)"

while IFS= read -r -d '' md; do
  dir="$(dirname "$md")"
  # strip fenced code blocks and inline code so documented examples aren't checked
  body=$(sed '/^```/,/^```/d' "$md" | sed 's/`[^`]*`//g')
  # extract markdown link targets: [text](target)
  targets=$(printf '%s\n' "$body" | grep -oE '\]\(([^)#]+)(#[^)]*)?\)' | sed -E 's/^\]\(([^)#]+)(#[^)]*)?\)$/\1/')
  while IFS= read -r target; do
    [ -z "$target" ] && continue
    case "$target" in
      http://*|https://*|mailto:*) continue ;;
    esac
    checked=$((checked + 1))
    if [ ! -e "$dir/$target" ]; then
      echo "BROKEN: $md -> $target"
      fail=1
    fi
  done <<EOF
$targets
EOF
done < <(find "$root" -name '*.md' -not -path '*/.freebuff/*' -print0)

if [ "$fail" -eq 0 ]; then
  echo "OK: $checked relative markdown links checked, all resolve."
else
  echo "FAIL: broken links found (see above)."
fi
exit "$fail"
