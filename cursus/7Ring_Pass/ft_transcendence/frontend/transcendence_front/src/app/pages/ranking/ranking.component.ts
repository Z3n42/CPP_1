import { Component, OnInit } from '@angular/core';
import { MenuComponent } from '../../shared/components/menu/menu.component';
import { FooterComponent } from '../../shared/components/footer/footer.component';
import { ApiService } from '../../core/services/api.service';
import { Player } from '../../core/models/ranking.model';
import { Game } from '../../core/models/ranking.model';
import { CommonModule } from '@angular/common';


@Component({
  selector: 'app-ranking',
  standalone: true,
  imports: [MenuComponent, FooterComponent, CommonModule],
  templateUrl: './ranking.component.html',
  styleUrl: './ranking.component.css'
})
export class RankingComponent implements OnInit{
  games: Game[] = [];
  ranking: Player[] = [];
  currentGamesPage: number = 1;
  currentRankingPage: number = 1;
  itemsPerPage: number = 8;

  constructor(private apiSrv: ApiService){};

  ngOnInit(): void {
    this.getGames()
  }

  getGames(){
    this.apiSrv.getGames().subscribe(
      (response) => {
        console.log(response);
        this.games = response.sort((a: Game, b: Game) => new Date(b.created_at).getTime() - new Date(a.created_at).getTime())
        this.calculateRanking();
      }, (error) => {
        console.log(error);
      }
    );
  }

  calculateRanking(): void {
    const playerStats: { [key: string]: Player } = {};

    this.games.forEach(game => {
      const playerX = game.player_x;
      const playerO = game.player_o;
      
      if (playerX) {
        if (!playerStats[playerX.username]) {
          playerStats[playerX.username] = { ...playerX };
        }
      }

      if (playerO) {
        if (!playerStats[playerO.username]) {
          playerStats[playerO.username] = { ...playerO };
        }
      }
      
      const winner = game.winner;

      if (winner) {
        playerStats[winner.username];
      }
    });

    this.ranking = Object.values(playerStats).sort((a, b) => b.wins - a.wins);
  }

    get paginatedGames(): any[] {
    const start = (this.currentGamesPage - 1) * this.itemsPerPage;
    const end = start + this.itemsPerPage;
    return this.games.slice(start, end);
  }

  nextGamesPage(): void {
    if (this.currentGamesPage * this.itemsPerPage < this.games.length) {
      this.currentGamesPage++;
    }
  }

  previousGamesPage(): void {
    if (this.currentGamesPage > 1) {
      this.currentGamesPage--;
    }
  }

  get paginatedRanking(): Player[] {
    const start = (this.currentRankingPage - 1) * this.itemsPerPage;
    const end = start + this.itemsPerPage;
    return this.ranking.slice(start, end);
  }

  nextRankingPage(): void {
    if (this.currentRankingPage * this.itemsPerPage < this.ranking.length) {
      this.currentRankingPage++;
    }
  }

  previousRankingPage(): void {
    if (this.currentRankingPage > 1) {
      this.currentRankingPage--;
    }
  }
}
