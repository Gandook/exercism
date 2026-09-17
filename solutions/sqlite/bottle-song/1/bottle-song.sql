-- Schema:
-- CREATE TABLE "bottle-song" (
--         start_bottles INTEGER NOT NULL,
--         take_down     INTEGER NOT NULL,
--         result        TEXT
-- );
-- Task: update bottle-song table and set the result based on the
-- start_bottles and take_down.

WITH RECURSIVE
    words(n, lower, cap) AS (
        VALUES
            (0, 'no', 'Zero'), (1, 'one', 'One'), (2, 'two', 'Two'), (3, 'three', 'Three'),
            (4, 'four', 'Four'), (5, 'five', 'Five'), (6, 'six', 'Six'), (7, 'seven', 'Seven'),
            (8, 'eight', 'Eight'), (9, 'nine', 'Nine'), (10, 'ten', 'Ten')
    ),

    verses AS (
        SELECT
            bs.rowid AS song_id,
            bs.start_bottles AS current_bottles,
            1 AS step
        FROM "bottle-song" bs

        UNION ALL

        SELECT
            v.song_id,
            v.current_bottles - 1,
            v.step + 1
        FROM verses v
        JOIN "bottle-song" bs ON v.song_id = bs.rowid
        WHERE v.step < bs.take_down
    ),

    formatted_verses AS (
        SELECT
            v.song_id,
            v.step,
        
            w1.cap || ' green ' ||
            CASE WHEN v.current_bottles = 1 THEN 'bottle' ELSE 'bottles' END ||
            ' hanging on the wall,' || x'0A' ||
            w1.cap || ' green ' ||
            CASE WHEN v.current_bottles = 1 THEN 'bottle' ELSE 'bottles' END ||
            ' hanging on the wall,' || x'0A' ||
            'And if one green bottle should accidentally fall,' || x'0A' ||
            'There''ll be ' || w2.lower || ' green ' ||
            CASE WHEN v.current_bottles = 2 THEN 'bottle' ELSE 'bottles' END ||
            ' hanging on the wall.' AS verse_text
        FROM verses v
        JOIN words w1 ON w1.n = v.current_bottles
        JOIN words w2 ON w2.n = v.current_bottles - 1
    )

UPDATE "bottle-song"
SET result = (
    SELECT GROUP_CONCAT(fv.verse_text, x'0A' || x'0A')
    FROM (
        SELECT * FROM formatted_verses
        ORDER BY step ASC
    ) fv
    WHERE fv.song_id = "bottle-song".rowid
    GROUP BY fv.song_id
);
