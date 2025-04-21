import datetime
from datetime import timedelta

class Account:
    def __init__(self, id: int, annualInterestRate: float):
        self.id = id
        self.balance = 0.0
        self.annualInterestRate = annualInterestRate
        self.createDate = datetime.datetime.now()
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


class ATM:
    def __init__(self):
        self.accounts = {}

    def add_account(self, account):
        self.accounts[account.id] = account

    def withdraw(self, account_id: int, amount: float):
        if account_id in self.accounts:
            self.accounts[account_id].withdraw(amount)
    def deposit(self, account_id: int, amount: float):
        if account_id in self.accounts:
            self.accounts[account_id].deposit(amount)

    def pass_day(self, days: int):
        for account in self.accounts.values():
            account.pass_days(days)

    def print_balance(self, account_id: int):
        if account_id in self.accounts:
            print(self.accounts[account_id].get_balance())


def main():
    n = int(input())
    atm = ATM()

    for _ in range(n):
        id, interest_rate = map(float, input().split())
        account = Account(int(id), interest_rate)
        atm.add_account(account)

    m = int(input())
    for _ in range(m):
        operation = list(map(float, input().split()))
        op_type = int(operation[0])
        if op_type == 0:
            atm.deposit(int(operation[1]), operation[2])
        elif op_type == 1:
            atm.withdraw(int(operation[1]), operation[2])
        elif op_type == 2:
            atm.pass_day(int(operation[1]))
        elif op_type == 3:
            atm.print_balance(int(operation[1]))


if __name__ == "__main__":
    main()