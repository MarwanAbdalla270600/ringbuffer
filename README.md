Diese Version ist mit semaphoren
,/script.sh zum erstellen der Dateien
Es muss ./receiver zuerst ausgeführt werden, sonst funktioniert es nicht 
danach ./sender x < input.txt ausgeführt werden x..anzahl der buffer elemente
im hintergrund wird immer in den buffer reingeschrieben und wenn er voll ist wird vom reciever entlert.
danach wird wieder vom sender reingeschrieben bis input.txt fertig ist. 
Fehlerhafte version teilwese, deswegen hab ich die andere version ohne semaphoren ebenfalls mit abgegeben