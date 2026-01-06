-- 코드를 입력하세요

SELECT user.user_id, user.nickname, sum(board.price) as total_sales from used_goods_user user join used_goods_board board on user.user_id = board.writer_id
where board.status = 'DONE' 
group by user.user_id, user.nickname having sum(board.price) >= 700000
order by total_sales asc;