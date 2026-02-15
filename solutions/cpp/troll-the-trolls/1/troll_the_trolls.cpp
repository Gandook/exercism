namespace hellmath {
    enum class AccountStatus {
    troll,
    guest,
    user,
    mod
    };

    enum class Action {
    read,
    write,
    remove
    };

    bool display_post(AccountStatus poster, AccountStatus viewer) {
        if (poster != AccountStatus::troll) {
            return true;
        }

        return viewer == AccountStatus::troll;
    }

    bool permission_check(Action action, AccountStatus status) {
        switch (status) {
        case AccountStatus::mod:
            return true;
        case AccountStatus::user:
        case AccountStatus::troll:
            return action != Action::remove;
        default:
            return action == Action::read;
        }
    }

    bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
        if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) {
            return false;
        }
        
        if (player1 == AccountStatus::troll) {
            return player2 == AccountStatus::troll;
        }

        return player2 != AccountStatus::troll;
    }

    bool has_priority(AccountStatus status1, AccountStatus status2) {
        return static_cast<int>(status1) > static_cast<int>(status2);
    }
}  // namespace hellmath
