 Quick Sort: rápido na prática, mas com ressalvas
✅ Por que é rápido?
Complexidade média: O(n log n)

Funciona in-place (não usa muita memória)

Cache-friendly: percorre os dados de forma sequencial (melhor uso da RAM)

Muito usado em bibliotecas padrão (ex: std::sort em C++)

❌ Mas nem sempre é o melhor:
Situação	Melhor escolha	Por quê?
Dados muito desordenados	Quick Sort	Eficiência média alta
Dados quase ordenados	Insertion Sort	Quase O(n)
Precisa de ordenação estável	Merge Sort	Mantém ordem de iguais
Dados pequenos	Insertion ou Bubble Sort	Simples, pouca sobrecarga
Pior caso do Quick Sort	Merge Sort / Heap Sort	Quick Sort vira O(n²) se pivô for ruim

🧪 Comparativo prático (tempo médio real)
Algoritmo	Complexidade média	Estável	Usa muita memória?	Rápido na prática?
Quick Sort	O(n log n)	❌	✅ Não (in-place)	✅✅✅ (muito rápido)
Merge Sort	O(n log n)	✅	❌ Sim	✅ (seguro, mas usa RAM)
Insertion Sort	O(n²), mas bom p/ quase ordenado	✅	✅	⚠️ (lento se grande)

