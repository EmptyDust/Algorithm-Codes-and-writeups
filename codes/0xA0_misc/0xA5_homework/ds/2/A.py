class SequenceList:
    def __init__(self, n, elements):
        """初始化顺序表"""
        if len(elements) != n:
            raise ValueError(f"输入的元素数量应为 {n}，实际为 {len(elements)}")
        self.data = elements
        print(f"顺序表创建成功: {self.data}")

    def insert(self, i, x):
        """在顺序表的第i个位置插入值为x的元素"""
        if i < 0 or i > len(self.data):
            raise IndexError(f"插入位置i不合法，合法范围为 0 ≤ i ≤ {len(self.data)}")
        self.data.insert(i, x)
        print(f"插入元素 {x} 后的顺序表: {self.data}")

    def delete(self, i):
        """删除顺序表中第i个元素"""
        if i < 0 or i >= len(self.data):
            raise IndexError(f"删除位置i不合法，合法范围为 0 ≤ i ≤ {len(self.data) - 1}")
        deleted_element = self.data.pop(i)
        print(f"删除元素 {deleted_element} 后的顺序表: {self.data}")

    def search(self, x):
        """查找顺序表中值为x的元素，返回其初次出现的位置"""
        try:
            index = self.data.index(x)
            print(f"元素 {x} 首次出现的位置为: {index}")
            return index
        except ValueError:
            print(f"元素 {x} 不存在于顺序表中")
            return -1

    def reverse(self):
        """将顺序表逆置"""
        self.data.reverse()
        print(f"逆置后的顺序表: {self.data}")


def main():
    n = int(input("请输入顺序表的长度: "))
    elements = [int(x) for x in input(f"请输入 {n} 个元素，用空格分隔: ").split()]
    seq_list = SequenceList(n, elements)

    while True:
        print("\n请选择操作：")
        print("1: 插入元素")
        print("2: 删除元素")
        print("3: 查找元素")
        print("4: 逆置顺序表")
        print("5: 显示顺序表")
        print("0: 退出")

        choice = int(input("请输入操作类型(0-5): "))

        if choice == 1:
            i = int(input("请输入要插入的位置 (0 ≤ i ≤ n): "))
            x = int(input("请输入要插入的元素: "))
            seq_list.insert(i, x)
        elif choice == 2:
            i = int(input("请输入要删除的元素位置 (0 ≤ i ≤ n-1): "))
            seq_list.delete(i)
        elif choice == 3:
            x = int(input("请输入要查找的元素: "))
            seq_list.search(x)
        elif choice == 4:
            seq_list.reverse()
        elif choice == 5:
            print(f"当前顺序表: {seq_list.data}")
        elif choice == 0:
            print("程序结束。")
            break
        else:
            print("无效的选择，请重新输入。")

if __name__ == "__main__":
    main()
