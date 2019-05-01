//参考：https://www.cnblogs.com/aeiou/p/5719396.html
//@是用户自定义变量的意思
select Scores.Score,t1.Rank from Scores join (SELECT Score,@rowNum:=@rowNum + 1 AS Rank FROM (select distinct Score from Scores order by Score desc) a,(SELECT @rowNum:=0) b) t1 on Scores.Score = t1.Score order by Scores.score desc;
