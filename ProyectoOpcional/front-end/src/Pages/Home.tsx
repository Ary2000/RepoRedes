import React, { useState, useRef } from 'react'
import { useNavigate } from 'react-router-dom';
import axios from "axios";

// Tutorial de routing https://www.youtube.com/watch?v=2aumoR0-jmQ&ab_channel=TheNerdyCanuck

export interface createBoardInterface {
  data:{
    _id: string
  }
}

export interface boardInterface {
  data:{
    board: {
      id_board?: number,
      status: number;
    }
  }
}

export const Home = () => {
  const [mensajeBusqueda, setMensajeBusqueda] = useState("Codigo de partida");
  const navigate = useNavigate();
  let codigo = "";

  async function crearPartida() {
    let resultado: createBoardInterface = await axios.get("http://localhost:80/crear").then();
    navigate('/anfitrion/' + resultado.data._id);
  }

  async function unirsePartida() {
    let resultado: boardInterface = await axios.get("http://127.0.0.1:80/searchBoardAnfitrion/" + codigo).then();
    switch(resultado.data.board.status) {
      case -1:{
        setMensajeBusqueda("Esta tabla no existe");
        break;
      }
      case 0: {
        setMensajeBusqueda("Esta tabla ya termino");
        break;
      }
      case 1: {
        navigate('/anfitrion/' + String(resultado.data.board.status))
      }
    }
  }

  async function buscarPartida() {
    let resultado: boardInterface = await axios.get("http://127.0.0.1:80/searchBoardInvitado/").then();
    switch(resultado.data.board.status) {
      case -1:{
        setMensajeBusqueda("Esta tabla no existe");
        break;
      }
      case 0: {
        setMensajeBusqueda("Esta tabla ya termino");
        break;
      }
      case 1: {
        navigate('/invitado/' + String(resultado.data.board.status));
      }
    }
  }


  return (
    <>
      <div style={{
        flex: '1000',
        alignItems: 'center',
        justifyContent: 'center',
        display: 'flex',
        flexDirection: 'column'}}>
        {/* https://images.chesscomfiles.com/uploads/v1/landing/370.8012fd8a.1052x270o.2672a973fb4d.jpg */}
        <img src={require('../imagenes/crazychess.jpg')}/>
        <h2>{mensajeBusqueda}</h2>
        <input
        onChange={(e) => {
          codigo = e.target.value
        } }/>
      </div>
      <div style={{
        padding: 20,
        alignItems: 'center',
        justifyContent: 'center',
        display: 'flex',}}>
        <div style={{
          width: '40%',
          alignItems: 'center',
          justifyContent: 'space-around',
          display: 'flex',
          flexDirection: 'row'}}>
            <button onClick={crearPartida}>Crear partida</button>
            <button onClick={unirsePartida}>Unirse a partida</button>
            <button onClick={buscarPartida}>Buscar partida</button>
        </div>
      </div>
    </>
  )
}
