/*

表: Orders

+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
在 SQL 中，Order_number是该表的主键。
此表包含关于订单ID和客户ID的信息。
 

查找下了 最多订单 的客户的 customer_number 。

测试用例生成后， 恰好有一个客户 比任何其他客户下了更多的订单。

查询结果格式如下所示。

 

示例 1:

输入: 
Orders 表:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
输出: 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
解释: 
customer_number 为 '3' 的顾客有两个订单，比顾客 '1' 或者 '2' 都要多，因为他们只有一个订单。
所以结果是该顾客的 customer_number ，也就是 3 。
 

进阶： 如果有多位顾客订单数并列最多，你能找到他们所有的 customer_number 吗？

*/


select customer_number
from orders
group by customer_number   //将 orders 表中的记录按照 customer_number 分组。也就是说，把拥有相同客户编号的订单归为一组。
order by count(*) desc     //按每组中的订单数量进行排序。count(*) 计算每个分组中的订单数量，desc 表示按降序排列，即订单数量最多的分组排在最前面。
limit 1;      //限制结果的行数为1，即只返回订单数量最多的那一个客户编号。