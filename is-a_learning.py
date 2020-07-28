# 前提
# premise='太郎 is-a 人間'
premise1='John is-a human'.split()
premise2='bird is-a animal'.split()

# 教師データ
question1='is John human ?'.split()
question2='is bird animal ?'.split()
question3='is not John human ?'.split()
question=['is John human ?'.split(),'is bird animal ?'.split(),'is not John human ?'.split()]

# question1='太郎 は 人間 か？'
# answer1='はい'
# reason1='太郎 is-a 人間'

answer1='Yes.'.split()
reason1=premise1

answer2='Yes.'.split()
reason2=premise2

answer3='Not.'.split()
reason3=premise1

"""
question2='太郎 は 人間 でない か？'
answer2='いいえ'
reason2='太郎 is-a 人間'
"""
# data=[[question1,answer1,reason1],[question2,answer2,reason2]]

# 学習
# 学習データの共通点探索、そこからのif文生成
InternalProcedureWord=""

for q in question1:
    for r in reason1:
        if(q==r):InternalProcedureWord=q
for q in question2:
    for r in reason2:
        if(q==r):InternalProcedureWord2=q

for q1 in question1:
    for q2 in question2:
        if(q1==q2):InternalProcedureIf=[q1,q2]

"""
# 内部手続き
def InternalProcedure(question):
    if(question.split()[1]==premise1.split()[0]
        and question.split()[2]==premise1.split()[2]):
        return 'Yes.'

# 学習データのみでのテスト
print(InternalProcedure('is John human ?'))
"""
print(premise1[1])

"""
print('太郎 は 人間 か？'.split()[0])
print(premise.split()[0])
print('太郎 は 人間 か？'.split()[2])
print(premise.split()[2])

print(premise.split())
print(question1.split())
print(premise==reason1)
print(data[1])
"""
