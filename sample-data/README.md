# Sample Data

Setiap folder terdiri dari:

| File            | Isi                                           |
| --------------- | --------------------------------------------- |
| `workspace.csv` | Versi format dan counter ID berikutnya.       |
| `pages.csv`     | Halaman dan parent-nya.                       |
| `blocks.csv`    | Isi blok, posisi, tipe, dan status checklist. |
| `links.csv`     | Link berarah antarhalaman.                    |
| `tags.csv`      | Katalog tag.                                  |
| `page_tags.csv` | Relasi halaman–tag.                           |

## jurnal/

```text
[P0] Workspace
  [P1] Jurnal Anomali
    [P3] Portal Kampus
  [P2] Rencana Mebel
```

- P1 memiliki B1 (TEXT). P3 memiliki B2 (CHECK DONE) dan B3 (CHECK TODO).
- Link: P2 -> P3 dan P3 -> P1.
- T1 **anomali** dipakai P1/P3; T2 **rencana** dipakai P2.
- ID berikutnya adalah **P4, B4, dan T3**.

## kosong/

`workspace.csv` berisi `1,1,1,1`; lima file lainnya hanya berisi header. Pembuatan pertama memakai P1/B1/T1 sesuai jenisnya. P0 merupakan akar virtual dan tidak disimpan sebagai record halaman.

Field `title` pada `pages.csv`, `text` pada `blocks.csv`, dan `name` pada `tags.csv` **wajib diapit tanda petik ganda**. Petik di dalam teks ditulis dua kali, misalnya `"Catatan, ""Portal Timur"""`.
