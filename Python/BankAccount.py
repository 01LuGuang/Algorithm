from datetime import datetime, timedelta
import sys

class Account:
    def __init__(self, id: int, annualInterestRate: float):
        self.id = id
        self.balance = 0.0
        self.annualInterestRate = annualInterestRate
        self.createDate = datetime.now()
        self.lastInterestDate = self.createDate  # 记录最后一次计息时间

    def _apply_interest(self, days: int):
        """
        根据天数计算复利，并更新余额。
        利息计算公式：A = P * (1 + r)^n
        r 是每天利率，n 是天数
        """
        if days <= 0:
            return
        daily_rate = self.annualInterestRate / 365
        self.balance *= (1 + daily_rate) ** days
        self.lastInterestDate += timedelta(days=days)

    def deposit(self, amount: float):
        """存款操作，存入当天开始计算利息"""
        self.balance += amount

    def withdraw(self, amount: float):
        """取款操作，如果余额不足，忽略操作"""
        if self.balance >= amount:
            self.balance -= amount
        else:
            print(f"余额不足，无法取出 {amount} 元")

    def pass_days(self, days: int):
        """模拟时间流逝days天并结算利息"""
        self._apply_interest(days)

    def get_balance(self):
        """获取当前余额，保留两位小数"""
        return round(self.balance, 2)


# 读取输入（支持命令行或交互式）
def main():
    # 创建账户，假设ID为1，初始年利率为0.05
    account = Account(1, 0.05)

    n = int(sys.stdin.readline())  # 读取操作次数
    for _ in range(n):
        parts = sys.stdin.readline().strip().split()
        op = int(parts[0])
        if op == 0:
            amount = float(parts[1])
            account.deposit(amount)
        elif op == 1:
            amount = float(parts[1])
            account.withdraw(amount)
        elif op == 2:
            days = int(parts[1])
            account.pass_days(days)
        elif op == 3:
            print(f"{account.get_balance():.2f}")

if __name__ == "__main__":
    main()
