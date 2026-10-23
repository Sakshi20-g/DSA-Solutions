# Write your MySQL query statement below
select
    ROUND(
        COUNT(DISTINCT a1.player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity)
    ,2) as fraction

from Activity a1
join Activity a2
on a1.player_id = a2.player_id
and DATEDIFF(a2.event_date,a1.event_date)=1
where a1.event_date = (
    select min(a3.event_date)
    from activity a3
    where a3.player_id = a1.player_id
);