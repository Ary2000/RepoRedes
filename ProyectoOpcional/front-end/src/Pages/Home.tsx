import React, { useState, useRef } from 'react'
import e, * as express from 'express'
import { useNavigate } from 'react-router-dom';

// Tutorial de routing https://www.youtube.com/watch?v=2aumoR0-jmQ&ab_channel=TheNerdyCanuck

export interface HomePageProps {}

export const Home = () => {
  const navigate = useNavigate();
  let codigo = "";

  function crearPartida() {
    // Pide el numero del tablero
    navigate('/anfitrion/');
  }

  function unirsePartida() {
    navigate('/anfitrion/' + codigo)
  }

  function buscarPartida() {
    navigate('/invitado/')
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
        <h2>Codigo de partida</h2>
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
