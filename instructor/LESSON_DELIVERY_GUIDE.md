# LESSON_DELIVERY_GUIDE.md — Lecture Delivery System

**Instructor-only.** Every lecture (L01–L32) has a delivery guide in
[lecture-delivery/](lecture-delivery/) — one file per module, two lectures each,
holding the full 21-field plan for each session (objectives, prep, concept
sequence, demo, prediction, case, guided practice, misconceptions, debugging,
independent practice, exit ticket, summary, support, extension, reflection).
This file defines the **timing frame** all 32 guides share, the guide anatomy,
and how to adapt. Per-lecture cut/extend decisions belong in your own pacing
notes; this file is the invariant.

---

## 1. The canonical 120-minute frame

| Segment | Minutes | Content (who runs it: see CLASSROOM_METHODOLOGY) |
|---|---|---|
| Opening and activation | **10** | Recall question built from last lecture's exit tickets + today's roadmap |
| Concept explanation | **30** | New material, motivation-first, in two pushes (≈ 20 + 10) around the demo |
| Demonstration | **15** | Live-coded example(s) from the lecture's example files, with one planned error |
| Guided practice | **20** | Whole-class trace/predict + pair work on the in-class exercise set |
| Case study / discussion | **15** | The lecture's anchor case, 5-minute protocol + debrief (METHOD § 3) |
| Independent practice | **20** | `exercises/in_class/` items, circulating TAs; support + extension active |
| Assessment / exit ticket | **5** | Two-question ticket defined in the lecture guide |
| Summary | **5** | Re-derive the lecture's one-sentence takeaway *by questioning*; preview next |
| **Total** | **120** | |

Non-negotiables:
- **The break**: the 60-minute wall is real. Where it falls: split concept
  explanation 20/10 around the demonstration → break sits at ≈ minute 60
  (after demonstration, before guided practice) on lecture-heavy days, or after
  guided practice on practice-heavy days. The per-lecture guides mark it.
- **Exit tickets are read before the next lecture** — they generate the next
  opening recall question. This loop is the course's early-warning system.
- Quiz days (every week *n*'s second lecture, 15 min, announced): take 10
  minutes from independent practice and 5 from guided practice. Timing still
  totals 120.
- Exam days (L16, L32) use the variant in § 3.

## 2. Anatomy of a per-lecture guide

Each guide in `lecture-delivery/mNN_*.md` contains, for each of its two lectures,
exactly these fields (numbered as in the enhancement spec):

1. Number & title · 2. Module/week · 3. Learning objectives (from the lecture
notes — never restated differently) · 4. Prerequisite knowledge · 5. Instructor
prep checklist · 6. Required materials & files · 7. Opening question · 8.
Concept introduction sequence · 9. Explanation guidance · 10. Live
demonstration (references `demonstrations/` where one exists) · 11.
Output-prediction activity · 12. Case study (anchor ID from `case-studies/`) ·
13. Guided coding activity · 14. Common misconceptions (bank IDs) · 15.
Debugging activity · 16. Independent practice (exercise IDs) · 17. Exit ticket ·
18. Summary · 19. Struggling-student support · 20. Extension · 21. Instructor
reflection questions — **plus the segment table totalling 120.**

The guide references validated lecture content; it never re-teaches it. If the
guide and the lecture notes ever disagree, the lecture notes win — file an issue
rather than improvising.

## 3. Timing variants (used where the guides say so)

| Variant | Change | Used by |
|---|---|---|
| Trace-heavy | Concept 25 · Guided 25 · Independent 15 | L06, L12, L24 (trace-table lectures) |
| Quiz day | Concept 30 · Guided 15 · Independent 10 · Quiz 15 | every week's second lecture |
| Exam day | L16: Opening 5 · Exam 100 · Take-up 15 · Ticket 5 · Summary 5 · L32: Opening 5 · Exam 110 · Ticket 5 · Summary 5 | L16, L32 |
| Case-heavy | Guided 15 · Case 20 | L06, L11, L27 (design/algorithm lectures) |
| Case-heavy ∩ quiz day (L22 hybrid) | Concept 25 · Guided 15 · Case 20 · Independent 10 · Quiz 15 | L22 only |

All variants total exactly 120. Do not invent further variants mid-semester;
consistency is the point.

## 4. Delivery quality bar (self-check after each lecture)

- Did students *predict* at least three times before seeing output?
- Did every segment change the students' activity (listen → predict → pair →
  type → discuss → write) at least six times?
- Did at least one planned error run its full course (predict → compile →
  diagnose → fix)?
- Were the exit tickets collected — and *read*?
- Did struggling students leave with a concrete next step (§ 19 of the guide)?

## 5. Related files

- Per-lecture guides: [lecture-delivery/](lecture-delivery/) (m01–m16)
- Formats, questioning ladder, case protocol: [CLASSROOM_METHODOLOGY.md](CLASSROOM_METHODOLOGY.md)
- Debugging method & diagnosis tables: [DEBUGGING_GUIDE.md](DEBUGGING_GUIDE.md)
- Demo scripts: [demonstrations/](demonstrations/) · Misconceptions: [misconception-bank/](misconception-bank/)
- Course-wide stance (unchanged): [../TEACHING_GUIDE.md](../TEACHING_GUIDE.md) — § 3's
  five-row pattern is preserved inside this frame (recall → concept → break →
  concept/practice → exercise + exit).
