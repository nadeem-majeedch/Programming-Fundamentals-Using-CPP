# Delivery Guide — Module 15 · File Handling and Error Management (Week 15)

**Guides:** L29, L30 · Frame & variants: [../LESSON_DELIVERY_GUIDE.md](../LESSON_DELIVERY_GUIDE.md)
**Formats:** [../CLASSROOM_METHODOLOGY.md](../CLASSROOM_METHODOLOGY.md) · **Bank:** [../misconception-bank/](../misconception-bank/)

---

## L29 · Text Files with `ifstream`/`ofstream`: Reading, Writing, Appending, EOF

1. **Lecture/title:** L29 — Text Files with `ifstream`/`ofstream`: Reading, Writing, Appending, EOF
2. **Module/week:** Module 15 · Week 15 · Lecture 1 of 2
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_15/lecture_29.md): [lecture_29.md](../../lectures/week_15/lecture_29.md)): open files for read/write/append; check open success; read with `>>` and `getline` past the whitespace trap; detect EOF correctly; write formatted records.
4. **Prerequisite knowledge:** L04 stream state; L21 getline discipline; L28 records (files of records today).
5. **Prep checklist:** compile `examples/file_read_write.cpp` this morning; prepare the *working-directory* explanation (where do created files go? — rehearse your IDE's cwd); create the sample data file(s) the demo reads; load PF-CS-081.
6. **Materials & files:** `examples/file_read_write.cpp`; case PF-CS-081 The Attendance Register File; [MC-23](../misconception-bank/misconception_bank.md) snippet; sample `students.txt` in the lab-15 style.
7. **Opening question (10):** "Everything this course has computed *vanished* at exit. A gradebook must outlive its run. What's the mechanism?" — persistence as the motivation; files as *the* stream they already know (cout = screen, ofstream = file — same operations).
8. **Concept sequence (30):** (a) the three open modes; open-failure reality (missing file, locked file, bad path) and the `if (!in)` guard (8); (b) reading: `>>` (token streams) vs `getline` (lines) — the L04 trap re-fires *with files* (12); (c) EOF: the read-as-condition idiom `while (getline(in, line))` vs the doomed `while (!in.eof())` (10).
9. **Explanation guidance:** `eof()` is the course's most honest trap lecture: show the doomed loop read one *extra* record (the last-line-double-processing artifact) before teaching the read-as-condition idiom — students must *see* the off-by-one file to believe the idiom. Working-directory confusion is the #1 lab-15 support call: demo `pwd`-dependence explicitly (run from two directories, watch "file not found" appear only once).
10. **Demonstration (15):** [DEMO-30](../demonstrations/demo_group6_memory_files_oop.md) — `file_read_write.cpp`: write records → read them back → append → verify; planned errors, two acts: (1) misspelled filename — the open-failure guard catches it *because it exists*; (2) the `while (!in.eof())` extra-record artifact.
11. **Output prediction:** the extra-record artifact (votes: "4 records" vs "last one twice" — the artifact is neither exactly, which is the point); what the append run adds vs overwrite.
12. **Case study (15):** **PF-CS-081 The Attendance Register File** — file-format design (one record per line? delimited how?) *before* code; format decisions drive parsing code — the design discipline from L11, now at the data-format level.
13. **Guided coding (20):** pairs write a records file from a vector<Student> and read it back, roundtrip verified; TAs attack: missing file, empty file, trailing newline, CRLF-pasted content — each attack has a *symptom* to classify.
14. **Common misconceptions:** [MC-23](../misconception-bank/misconception_bank.md) (open-failure ignored: reads "succeed" silently producing garbage/nothing); the eof() off-by-one (today's star); getline-after-`>>` (L04's MC-13, files edition).
15. **Debugging activity:** symptom: "my program reads zero records from a file that exists" — three candidates: wrong cwd, open-failure unchecked (guard missing), reading the wrong variable; the two-directory replay locates it.
16. **Independent practice (20):** T11 items (roundtrip, append, EOF forms); DS students: DS-10/DS-11 (dataset files — the *actual* use case they'll meet in stats courses).
17. **Exit ticket (5):** (1) Why is `while (getline(in, line))` the honest loop? (2) Your file has 5 records; the doomed eof-loop processes how many *reads*?
18. **Summary (5):** derive: "files are streams that persist — every stream lesson from L04 onward applies, plus the file system can say no."
19. **Support:** the read-as-condition sticky note; cwd-check ritual card (print the path the program *expects* before debugging "missing" files).
20. **Extension:** write the CSV variant and debate format robustness (what if a field contains a comma?) — feeds PF-CS-056 as stretch.
21. **Reflection:** who's eof-looping still? (Quiz 11 + lab 15 will catch it — flag names.) Did the format-design case land the "parse follows format" idea?

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 20 |
| Case study/discussion | 15 |
| Independent practice | 20 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |

---

## L30 · Robust Programs: Stream State, Error Checking, Recovery Strategies

1. **Lecture/title:** L30 — Robust Programs: Stream State, Error Checking, Recovery Strategies
2. **Module/week:** Module 15 · Week 15 · Lecture 2 of 2 — **QUIZ DAY** (Quiz 11)
3. **Objectives** (authoritative: [lecture notes](../../lectures/week_15/lecture_30.md): [lecture_30.md](../../lectures/week_15/lecture_30.md)): explain the stream state flags (good/fail/eof/bad); repair failed input with `clear()`/`ignore()`; implement the three response tiers (re-prompt, skip-and-report, fatal-with-message); use exceptions minimally and correctly; design robust I/O pipelines.
4. **Prerequisite knowledge:** L29 files; L04 stream basics; L13 function design.
5. **Prep checklist:** quiz 11 staged; compile `examples/robust_pipeline.cpp` this morning; rehearse the clear/ignore repair live (know your platform's `numeric_limits` include); load PF-CS-085 + PF-CS-086.
6. **Materials & files:** `examples/robust_pipeline.cpp`; cases PF-CS-085 Retry-Safe Config Loader, PF-CS-086 The Error-Message Designer; quiz 11 + key.
7. **Opening question (10):** replay of L04's failed-read — but now the question is *"what should a program DO when the user types 'abc' at an age prompt?"* Three behaviors elicited: crash, lie, or ask again — robustness is choosing deliberately.
8. **Concept sequence (30):** (a) stream state: the four flags as traffic lights; failed reads leave the stream *stuck* until cleared (10); (b) the repair idiom: `clear()` + `ignore(...)` — unblock the pipe, drain the junk (10); (c) the three tiers: retry (user-fixable), skip-and-report (data-level), fatal-with-message (unrecoverable) — decision rule per tier (10).
9. **Explanation guidance:** the tiers are the lecture's spine — every input point in every future program gets a *deliberate* tier choice. `cin.clear()` fixes the state; `cin.ignore(numeric_limits<streamsize>::max(), '\n')` drains the line — teach both as a *pair*, always. Exceptions: the course's honest scope statement — taught as the *library's* error channel (files, vector::at), used read-and-respond style (`try` around the operation, `catch (const std::exception& e)` with a message), never as a control-flow design tool; streaming arithmetic code doesn't throw, so no speculative try-wrapping.
10. **Demonstration (15):** [DEMO-31](../demonstrations/demo_group6_memory_files_oop.md) — `robust_pipeline.cpp`: bounded re-prompt loop with full state repair; skip-and-report over a messy dataset file; one fatal path with a clean message and `return 1`; planned error: `clear()` *without* `ignore()` — the junk stays, the loop spins: the pipe picture explains it instantly.
11. **Output prediction:** the clear-without-ignore spin (votes on "how many prompts before it accepts?"); the skip-and-report tally on a 5-line dataset with 2 bad rows.
12. **Case study (15):** **PF-CS-086 The Error-Message Designer** — error messages as a *design* artifact: what to say, what to log, what to never say (blame, internals); class critiques real bad messages then designs good ones.
13. **Guided coding (15 — quiz-day trim):** pairs harden L29's roundtrip with a tier-1 re-prompt on every numeric read and tier-2 skip-report on bad records; TAs attack with the full garbage battery.
14. **Common misconceptions:** clear-without-ignore (the demo); "robust = try/catch everywhere" (scope statement from (c) is the correction); tier-2 used where tier-1 fits (data errors vs user errors).
15. **Debugging activity:** symptom: "my re-prompt loop accepts the bad input on the second try — sometimes" — the missing drain; trace the pipe state across two attempts.
16. **Independent practice (10 — quiz-day trim):** one hardening item from T11 + one exception-read item (`vector::at` vs `[` — deliberate boundary exception).
17. **Quiz 11 (15):** per cadence.
18. **Exit ticket (5):** (1) Name the three tiers with one example each. (2) What does `ignore` do that `clear` doesn't?
19. **Summary (5):** the tier decision rule derived from the class's hardening choices; Module 16 tease: "data plus behavior, finally in one type."
20. **Support:** the three-tier decision card; repair-idiom sticky note (`clear` + `ignore`, always together).
21. **Reflection:** are students' lab-15 programs *hardened* or decorated? (Tier choices must be justifiable — ask two students why their tiers differ for similar inputs.) Quiz 11 flags: who confuses fail vs bad?

| Segment | Min |
|---|---|
| Opening and activation | 10 |
| Concept explanation | 30 |
| Demonstration | 15 |
| Guided practice | 15 |
| Case study/discussion | 15 |
| Independent practice | 10 |
| Quiz 11 | 15 |
| Assessment/exit ticket | 5 |
| Summary | 5 |
| **Total** | **120** |
