

--select top3 rated rooms
select name, rank from (
    select facs.name as name, rank() over (
        order by sum(case
            when memid=0 then slots * facs.guestcost
            else slots*facs.membercost
            end
        ) desc) as rank
    from cd.bookings bks
        inner join cd.facilities facs
            on bks.facid = facs.facid
    group by facs.name
    ) as subq
where rank <=3
order by rank asc;



