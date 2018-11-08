g1 = 7
g2 = 8
md = (g1 + 2 * g2)/3

print("Nota g1:", g1)
print("Nota g2:", g2)
print("Media final: %.2f" % (md), "- Aluno", ("aprovado." if md >= 6 else "em substituicao."))