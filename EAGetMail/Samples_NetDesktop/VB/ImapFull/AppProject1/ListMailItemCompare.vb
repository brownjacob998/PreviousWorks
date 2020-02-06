Class ListMailItemCompare
    Implements IComparer
    ' Compare for ListViewMail sort
    Public Function IComparer_Compare(x As Object, y As Object) As Integer Implements IComparer.Compare
        Dim itemx As ListViewItem = TryCast(x, ListViewItem)
        Dim itemy As ListViewItem = TryCast(y, ListViewItem)

        Dim sx As String = itemx.SubItems(2).Text
        Dim sy As String = itemy.SubItems(2).Text

        If sx.Length <> sy.Length Then Return -1

        Dim count As Integer = sx.Length
        For i As Integer = 0 To count - 1

            If sx(i) > sy(i) Then
                Return -1
            ElseIf sx(i) < sy(i) Then
                Return 1
            End If
        Next

        Return 0
    End Function
End Class