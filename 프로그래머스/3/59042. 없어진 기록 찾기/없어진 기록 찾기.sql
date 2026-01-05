-- 코드를 입력하세요
-- 입양 간 기록 존재, 보호소 들어온 기록 X 동물 Id, 이름을 id 순으로 조회 
-- left join으로 풀기 
SELECT a.animal_id, a.name  from animal_outs a left join animal_ins b on a.animal_id = b.animal_id where b.animal_id is null order by a.animal_id;